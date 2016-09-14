namespace NiXnetTestApp
{
   partial class Form1
   {
      /// <summary>
      /// Required designer variable.
      /// </summary>
      private System.ComponentModel.IContainer components = null;

      /// <summary>
      /// Clean up any resources being used.
      /// </summary>
      /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
      protected override void Dispose( bool disposing )
      {
         if ( disposing && ( components != null ) )
         {
            components.Dispose();
         }
         base.Dispose( disposing );
      }

      #region Windows Form Designer generated code

      /// <summary>
      /// Required method for Designer support - do not modify
      /// the contents of this method with the code editor.
      /// </summary>
      private void InitializeComponent()
      {
         this.components = new System.ComponentModel.Container();
         System.Windows.Forms.ColumnHeader columnHeader1;
         System.Windows.Forms.ColumnHeader columnHeader2;
         System.Windows.Forms.ColumnHeader columnHeader3;
         this.m_devices = new System.Windows.Forms.ListBox();
         this.m_refreshDevices = new System.Windows.Forms.Button();
         this.m_interfaces = new System.Windows.Forms.ListBox();
         this.label1 = new System.Windows.Forms.Label();
         this.groupBox1 = new System.Windows.Forms.GroupBox();
         this.groupBox2 = new System.Windows.Forms.GroupBox();
         this.label2 = new System.Windows.Forms.Label();
         this.m_databaseName = new System.Windows.Forms.TextBox();
         this.m_browseForDatabaseButton = new System.Windows.Forms.Button();
         this.label3 = new System.Windows.Forms.Label();
         this.m_openDatabaseDialog = new System.Windows.Forms.OpenFileDialog();
         this.m_clusters = new System.Windows.Forms.ListBox();
         this.m_signals = new System.Windows.Forms.ListBox();
         this.label4 = new System.Windows.Forms.Label();
         this.m_frames = new System.Windows.Forms.ListBox();
         this.label5 = new System.Windows.Forms.Label();
         this.m_ecus = new System.Windows.Forms.ListBox();
         this.label6 = new System.Windows.Forms.Label();
         this.m_startSessionButton = new System.Windows.Forms.Button();
         this.m_refreshVauesTimer = new System.Windows.Forms.Timer(this.components);
         this.m_values = new System.Windows.Forms.ListView();
         columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
         columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
         columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
         this.groupBox1.SuspendLayout();
         this.groupBox2.SuspendLayout();
         this.SuspendLayout();
         // 
         // m_devices
         // 
         this.m_devices.FormattingEnabled = true;
         this.m_devices.Location = new System.Drawing.Point(6, 48);
         this.m_devices.Name = "m_devices";
         this.m_devices.Size = new System.Drawing.Size(222, 56);
         this.m_devices.TabIndex = 0;
         this.m_devices.SelectedIndexChanged += new System.EventHandler(this.m_devices_SelectedIndexChanged);
         // 
         // m_refreshDevices
         // 
         this.m_refreshDevices.Location = new System.Drawing.Point(6, 19);
         this.m_refreshDevices.Name = "m_refreshDevices";
         this.m_refreshDevices.Size = new System.Drawing.Size(222, 23);
         this.m_refreshDevices.TabIndex = 1;
         this.m_refreshDevices.Text = "Refresh Devices";
         this.m_refreshDevices.UseVisualStyleBackColor = true;
         this.m_refreshDevices.Click += new System.EventHandler(this.m_refreshDevices_Click);
         // 
         // m_interfaces
         // 
         this.m_interfaces.FormattingEnabled = true;
         this.m_interfaces.Location = new System.Drawing.Point(6, 127);
         this.m_interfaces.Name = "m_interfaces";
         this.m_interfaces.Size = new System.Drawing.Size(222, 69);
         this.m_interfaces.TabIndex = 2;
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(7, 111);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(57, 13);
         this.label1.TabIndex = 3;
         this.label1.Text = "Interfaces:";
         // 
         // groupBox1
         // 
         this.groupBox1.Controls.Add(this.m_refreshDevices);
         this.groupBox1.Controls.Add(this.label1);
         this.groupBox1.Controls.Add(this.m_devices);
         this.groupBox1.Controls.Add(this.m_interfaces);
         this.groupBox1.Location = new System.Drawing.Point(12, 12);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Size = new System.Drawing.Size(235, 210);
         this.groupBox1.TabIndex = 4;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Devices";
         // 
         // groupBox2
         // 
         this.groupBox2.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
         this.groupBox2.Controls.Add(this.m_values);
         this.groupBox2.Controls.Add(this.m_startSessionButton);
         this.groupBox2.Controls.Add(this.m_ecus);
         this.groupBox2.Controls.Add(this.label6);
         this.groupBox2.Controls.Add(this.m_frames);
         this.groupBox2.Controls.Add(this.label5);
         this.groupBox2.Controls.Add(this.m_signals);
         this.groupBox2.Controls.Add(this.label4);
         this.groupBox2.Controls.Add(this.m_clusters);
         this.groupBox2.Controls.Add(this.label3);
         this.groupBox2.Controls.Add(this.m_browseForDatabaseButton);
         this.groupBox2.Controls.Add(this.m_databaseName);
         this.groupBox2.Controls.Add(this.label2);
         this.groupBox2.Location = new System.Drawing.Point(253, 12);
         this.groupBox2.Name = "groupBox2";
         this.groupBox2.Size = new System.Drawing.Size(547, 391);
         this.groupBox2.TabIndex = 5;
         this.groupBox2.TabStop = false;
         this.groupBox2.Text = "Database";
         // 
         // label2
         // 
         this.label2.AutoSize = true;
         this.label2.Location = new System.Drawing.Point(7, 19);
         this.label2.Name = "label2";
         this.label2.Size = new System.Drawing.Size(53, 13);
         this.label2.TabIndex = 0;
         this.label2.Text = "Database";
         // 
         // m_databaseName
         // 
         this.m_databaseName.Location = new System.Drawing.Point(68, 16);
         this.m_databaseName.Name = "m_databaseName";
         this.m_databaseName.Size = new System.Drawing.Size(406, 20);
         this.m_databaseName.TabIndex = 1;
         // 
         // m_browseForDatabaseButton
         // 
         this.m_browseForDatabaseButton.Location = new System.Drawing.Point(480, 16);
         this.m_browseForDatabaseButton.Name = "m_browseForDatabaseButton";
         this.m_browseForDatabaseButton.Size = new System.Drawing.Size(61, 20);
         this.m_browseForDatabaseButton.TabIndex = 2;
         this.m_browseForDatabaseButton.Text = "...";
         this.m_browseForDatabaseButton.UseVisualStyleBackColor = true;
         this.m_browseForDatabaseButton.Click += new System.EventHandler(this.m_browseForDatabaseButton_Click);
         // 
         // label3
         // 
         this.label3.AutoSize = true;
         this.label3.Location = new System.Drawing.Point(13, 63);
         this.label3.Name = "label3";
         this.label3.Size = new System.Drawing.Size(47, 13);
         this.label3.TabIndex = 3;
         this.label3.Text = "Clusters:";
         // 
         // m_openDatabaseDialog
         // 
         this.m_openDatabaseDialog.FileName = "c:\\work\\SeqZap\\trunk\\Test\\Customers\\Grundfos\\LIN\\LINbusDebugProfile_EuP_XL.ldf";
         this.m_openDatabaseDialog.Filter = "LIN Description Files|*.ldf|All files|*.*";
         // 
         // m_clusters
         // 
         this.m_clusters.FormattingEnabled = true;
         this.m_clusters.Location = new System.Drawing.Point(16, 79);
         this.m_clusters.Name = "m_clusters";
         this.m_clusters.Size = new System.Drawing.Size(120, 95);
         this.m_clusters.TabIndex = 4;
         this.m_clusters.SelectedIndexChanged += new System.EventHandler(this.m_clusters_SelectedIndexChanged);
         // 
         // m_signals
         // 
         this.m_signals.FormattingEnabled = true;
         this.m_signals.Location = new System.Drawing.Point(412, 79);
         this.m_signals.Name = "m_signals";
         this.m_signals.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
         this.m_signals.Size = new System.Drawing.Size(120, 95);
         this.m_signals.TabIndex = 6;
         // 
         // label4
         // 
         this.label4.AutoSize = true;
         this.label4.Location = new System.Drawing.Point(409, 63);
         this.label4.Name = "label4";
         this.label4.Size = new System.Drawing.Size(44, 13);
         this.label4.TabIndex = 5;
         this.label4.Text = "Signals:";
         // 
         // m_frames
         // 
         this.m_frames.FormattingEnabled = true;
         this.m_frames.Location = new System.Drawing.Point(280, 79);
         this.m_frames.Name = "m_frames";
         this.m_frames.Size = new System.Drawing.Size(120, 95);
         this.m_frames.TabIndex = 8;
         this.m_frames.SelectedIndexChanged += new System.EventHandler(this.m_frames_SelectedIndexChanged);
         // 
         // label5
         // 
         this.label5.AutoSize = true;
         this.label5.Location = new System.Drawing.Point(277, 63);
         this.label5.Name = "label5";
         this.label5.Size = new System.Drawing.Size(44, 13);
         this.label5.TabIndex = 7;
         this.label5.Text = "Frames:";
         // 
         // m_ecus
         // 
         this.m_ecus.FormattingEnabled = true;
         this.m_ecus.Location = new System.Drawing.Point(148, 79);
         this.m_ecus.Name = "m_ecus";
         this.m_ecus.Size = new System.Drawing.Size(120, 95);
         this.m_ecus.TabIndex = 10;
         this.m_ecus.SelectedIndexChanged += new System.EventHandler(this.m_ecus_SelectedIndexChanged);
         // 
         // label6
         // 
         this.label6.AutoSize = true;
         this.label6.Location = new System.Drawing.Point(145, 63);
         this.label6.Name = "label6";
         this.label6.Size = new System.Drawing.Size(37, 13);
         this.label6.TabIndex = 9;
         this.label6.Text = "ECUs:";
         // 
         // m_startSessionButton
         // 
         this.m_startSessionButton.Location = new System.Drawing.Point(16, 203);
         this.m_startSessionButton.Name = "m_startSessionButton";
         this.m_startSessionButton.Size = new System.Drawing.Size(75, 23);
         this.m_startSessionButton.TabIndex = 11;
         this.m_startSessionButton.Text = "Start Session";
         this.m_startSessionButton.UseVisualStyleBackColor = true;
         this.m_startSessionButton.Click += new System.EventHandler(this.m_startSessionButton_Click);
         // 
         // m_refreshVauesTimer
         // 
         this.m_refreshVauesTimer.Interval = 1000;
         this.m_refreshVauesTimer.Tick += new System.EventHandler(this.m_refreshVauesTimer_Tick);
         // 
         // m_values
         // 
         this.m_values.Activation = System.Windows.Forms.ItemActivation.OneClick;
         this.m_values.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
         this.m_values.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            columnHeader1,
            columnHeader2,
            columnHeader3});
         this.m_values.FullRowSelect = true;
         this.m_values.GridLines = true;
         this.m_values.HideSelection = false;
         this.m_values.HoverSelection = true;
         this.m_values.Location = new System.Drawing.Point(148, 203);
         this.m_values.Name = "m_values";
         this.m_values.Size = new System.Drawing.Size(384, 182);
         this.m_values.TabIndex = 12;
         this.m_values.UseCompatibleStateImageBehavior = false;
         this.m_values.View = System.Windows.Forms.View.Details;
         // 
         // columnHeader1
         // 
         columnHeader1.Text = "Signal";
         columnHeader1.Width = 150;
         // 
         // columnHeader2
         // 
         columnHeader2.Text = "Value";
         // 
         // columnHeader3
         // 
         columnHeader3.Text = "Timestamp";
         columnHeader3.Width = 140;
         // 
         // Form1
         // 
         this.ClientSize = new System.Drawing.Size(812, 415);
         this.Controls.Add(this.groupBox2);
         this.Controls.Add(this.groupBox1);
         this.Name = "Form1";
         this.groupBox1.ResumeLayout(false);
         this.groupBox1.PerformLayout();
         this.groupBox2.ResumeLayout(false);
         this.groupBox2.PerformLayout();
         this.ResumeLayout(false);

      }

      #endregion

      private System.Windows.Forms.ListBox m_devices;
      private System.Windows.Forms.Button m_refreshDevices;
      private System.Windows.Forms.ListBox m_interfaces;
      private System.Windows.Forms.Label label1;
      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.GroupBox groupBox2;
      private System.Windows.Forms.Label label2;
      private System.Windows.Forms.Button m_browseForDatabaseButton;
      private System.Windows.Forms.TextBox m_databaseName;
      private System.Windows.Forms.Label label3;
      private System.Windows.Forms.OpenFileDialog m_openDatabaseDialog;
      private System.Windows.Forms.ListBox m_clusters;
      private System.Windows.Forms.ListBox m_frames;
      private System.Windows.Forms.Label label5;
      private System.Windows.Forms.ListBox m_signals;
      private System.Windows.Forms.Label label4;
      private System.Windows.Forms.ListBox m_ecus;
      private System.Windows.Forms.Label label6;
      private System.Windows.Forms.Button m_startSessionButton;
      private System.Windows.Forms.Timer m_refreshVauesTimer;
      private System.Windows.Forms.ListView m_values;
   }
}

