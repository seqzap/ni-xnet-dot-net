#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetEcu::NiXnetEcu(nxDatabaseRef_t _handle)
   : m_handle(_handle)
{
}

NetString NiXnetEcu::Name::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropECU_Name);
}

cli::array<NiXnetFrame^>^ NiXnetEcu::FramesReceived::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropECU_RxFrmRefs);
   cli::array<NiXnetFrame^>^ frames = gcnew cli::array<NiXnetFrame^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      frames[i] = gcnew NiXnetFrame(handles[i]);
   }
   return frames;
}

cli::array<NiXnetFrame^>^ NiXnetEcu::FramesTansmitted::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropECU_TxFrmRefs);
   cli::array<NiXnetFrame^>^ frames = gcnew cli::array<NiXnetFrame^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      frames[i] = gcnew NiXnetFrame(handles[i]);
   }
   return frames;
}

bool NiXnetEcu::LinMaster::get()
{
   return NiXnet::GetDbValue<bool>(m_handle, nxPropECU_LINMaster);
}

NiXnetLinProtocolVersion NiXnetEcu::LinVersion::get()
{
   return static_cast<NiXnetLinProtocolVersion>(NiXnet::GetDbValue<u32>(m_handle, nxPropECU_LINProtocolVer));
}

NetString NiXnetEcu::ToString()
{
   return this->Name;
}
