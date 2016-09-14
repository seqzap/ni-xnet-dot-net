using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using NiXnetDotNet;

namespace NiXnetTestApp
{
   public partial class Form1 : Form
   {
      private NiXnetSystem m_system = null;
      private NiXnetDataBase m_database = null;
      private NiXnetSession m_session = null;

      public Form1()
      {
         InitializeComponent();
      }

      private void m_refreshDevices_Click( object sender, EventArgs e )
      {
         if ( m_system == null )
         {
            m_system = new NiXnetSystem();
         }
         m_interfaces.Items.Clear();
         m_devices.Items.Clear();
         foreach ( NiXnetDevice device in m_system.ListDevices() )
         {
            m_devices.Items.Add( device );
         }
      }

      private void m_devices_SelectedIndexChanged( object sender, EventArgs e )
      {
         m_interfaces.Items.Clear();
         NiXnetDevice device = (NiXnetDevice) m_devices.SelectedItem;
         foreach ( NiXnetInterface iface in device.Interfaces )
         {
            m_interfaces.Items.Add( String.Format( "{0}: {1} {2} {3}", iface.Number, iface.Name, iface.PortNumber, iface.Protocol ) );
         }
      }

      private void m_browseForDatabaseButton_Click( object sender, EventArgs e )
      {
         if ( m_openDatabaseDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK )
         {
            m_databaseName.Clear();
            m_clusters.Items.Clear();
            m_ecus.Items.Clear();
            m_signals.Items.Clear();
            m_frames.Items.Clear();
            if ( m_database != null )
            {
               m_database.Dispose();
               m_database = null;
            }
            m_database = new NiXnetDataBase( m_openDatabaseDialog.FileName );
            m_databaseName.Text = m_openDatabaseDialog.FileName;
            foreach ( NiXnetCluster cluster in m_database.Clusters )
            {
               m_clusters.Items.Add( cluster );
            }
         }
      }

      private void m_clusters_SelectedIndexChanged( object sender, EventArgs e )
      {
         NiXnetCluster cluster = m_clusters.SelectedItem as NiXnetCluster;
         m_ecus.Items.Clear();
         m_signals.Items.Clear();
         m_frames.Items.Clear();
         if ( cluster != null )
         {
            foreach ( NiXnetEcu ecu in cluster.Ecus )
            {
               m_ecus.Items.Add( ecu );
            }
         }
      }

      private void m_ecus_SelectedIndexChanged( object sender, EventArgs e )
      {
         NiXnetEcu ecu = m_ecus.SelectedItem as NiXnetEcu;
         m_frames.Items.Clear();
         if ( ecu != null )
         {
            foreach ( NiXnetFrame frame in ecu.FramesReceived )
            {
               m_frames.Items.Add( frame );
            }

            foreach ( NiXnetFrame frame in ecu.FramesTansmitted )
            {
               m_frames.Items.Add( frame );
            }
         }
      }

      private void m_frames_SelectedIndexChanged( object sender, EventArgs e )
      {
         NiXnetFrame frame = m_frames.SelectedItem as NiXnetFrame;
         if ( frame != null )
         {
            m_signals.Items.Clear();
            foreach ( NiXnetSignal signal in frame.Signals )
            {
               m_signals.Items.Add( signal );
            }
         }
      }

      private void m_startSessionButton_Click( object sender, EventArgs e )
      {
         if ( m_session != null )
         {
            m_session.Dispose();
         }
         /*
         string[] signals = new string[m_signals.SelectedItems.Count];
         int i = 0;
         foreach ( NiXnetSignal signal in m_signals.SelectedItems )
         {
            signals[i++] = signal.Name;
         }
          * */
         List<string> signals = new List<string>();
         foreach ( NiXnetSignal signal in ( m_clusters.Items[0] as NiXnetCluster ).Signals )
         {
            signals.Add( signal.Name );
         }
         m_session = new NiXnetSession( m_databaseName.Text, m_clusters.Items[0].ToString(), signals.ToArray(), "LIN1", NiXnetMode.SignalInSinglePoint );
         //m_session.Start( NiXnetScope.Normal );
         m_session.LinMaster = true;
         m_session.LinScheduleIndex = 1;
         m_refreshVauesTimer.Start();
      }

      private void m_refreshVauesTimer_Tick( object sender, EventArgs e )
      {
         string[] names = m_session.FramesOrSignals;
         Tuple<double, DateTime>[] values = m_session.ReadSignalSinglePoint();
         bool update = true;
         if ( names.Length != m_values.Items.Count || values.Length != m_values.Items.Count )
         {
            update = false;
            m_values.Items.Clear();
         }
         for ( int i = 0; i < names.Length && i < values.Length; i++ )
         {
            if ( update )
            {
               m_values.Items[i].SubItems[1].Text = values[i].Item1.ToString();
               m_values.Items[i].SubItems[2].Text = values[i].Item2.ToString();
            }
            else
            {
               ListViewItem item = m_values.Items.Add( names[i] );
               item.SubItems.Add( values[i].Item1.ToString() );
               item.SubItems.Add( values[i].Item2.ToString() );
            }
         }
      }
   }
}
