#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetSystem::NiXnetSystem()
{
   cli::pin_ptr<nxSessionRef_t> pointerToSession = &m_session;
   NiXnet::CheckStatus(nxSystemOpen(pointerToSession));
}

cli::array<NiXnetDevice^>^ NiXnetSystem::ListDevices()
{
   cli::array<u32>^ handles = NiXnet::GetArrayValue<u32>(m_session, nxPropSys_DevRefs);
   cli::array<NiXnetDevice^>^ devices = gcnew cli::array<NiXnetDevice^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      devices[i] = gcnew NiXnetDevice(handles[i]);
   }
   return devices;
}

cli::array<NiXnetInterface^>^ NiXnetSystem::Interfaces::get()
{
   cli::array<u32>^ handles = NiXnet::GetArrayValue<u32>(m_session, nxPropSys_IntfRefs);
   cli::array<NiXnetInterface^>^ interfaces = gcnew cli::array<NiXnetInterface^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      interfaces[i] = gcnew NiXnetInterface(handles[i]);
   }
   return interfaces;
}

NiXnetSystem::~NiXnetSystem()
{
   NiXnet::CheckStatus(nxSystemClose(m_session));
}
