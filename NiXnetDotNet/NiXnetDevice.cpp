#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetDevice::NiXnetDevice(u32 _handle)
   : m_handle(_handle)
{
}

NetString NiXnetDevice::ProductName::get()
{
   return NiXnet::GetStringValue(m_handle, nxPropDev_Name);
}

u32 NiXnetDevice::ProductNumber::get()
{
   return NiXnet::GetValue<u32>(m_handle, nxPropDev_ProductNum);
}

u32 NiXnetDevice::SerialNumber::get()
{
   return NiXnet::GetValue<u32>(m_handle, nxPropDev_SerNum);
}

cli::array<NiXnetInterface^>^ NiXnetDevice::Interfaces::get()
{
   cli::array<u32>^ handles = NiXnet::GetArrayValue<u32>(m_handle, nxPropDev_IntfRefs);
   cli::array<NiXnetInterface^>^ interfaces = gcnew cli::array<NiXnetInterface^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      interfaces[i] = gcnew NiXnetInterface(handles[i]);
   }
   return interfaces;
}

NetString NiXnetDevice::ToString()
{
   return System::String::Format("{0} ({1})", this->ProductName, this->SerialNumber);
}
