#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetCluster::NiXnetCluster(nxDatabaseRef_t _handle)
   : m_handle(_handle)
{
}


NetString NiXnetCluster::Name::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropClst_Name);
}

NiXnetProtocol NiXnetCluster::Protocol::get()
{
   return static_cast<NiXnetProtocol>(NiXnet::GetDbValue<u32>(m_handle, nxPropClst_Protocol));
}

cli::array<NiXnetEcu^>^ NiXnetCluster::Ecus::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_ECURefs);
   cli::array<NiXnetEcu^>^ ecus = gcnew cli::array<NiXnetEcu^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      ecus[i] = gcnew NiXnetEcu(handles[i]);
   }
   return ecus;
}

cli::array<NiXnetFrame^>^ NiXnetCluster::Frames::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_FrmRefs);
   cli::array<NiXnetFrame^>^ frames = gcnew cli::array<NiXnetFrame^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      frames[i] = gcnew NiXnetFrame(handles[i]);
   }
   return frames;
}

cli::array<NiXnetSignal^>^ NiXnetCluster::Signals::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_SigRefs);
   cli::array<NiXnetSignal^>^ signals = gcnew cli::array<NiXnetSignal^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      signals[i] = gcnew NiXnetSignal(handles[i]);
   }
   return signals;
}

cli::array<NiXnetLinSchedule^>^ NiXnetCluster::LinSchedules::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropClst_LINSchedules);
   cli::array<NiXnetLinSchedule^>^ schedules = gcnew cli::array<NiXnetLinSchedule^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      schedules[i] = gcnew NiXnetLinSchedule(handles[i]);
   }
   return schedules;
}

NetString NiXnetCluster::ToString()
{
   return this->Name;
}
