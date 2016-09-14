#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetInterface::NiXnetInterface(u32 _handle)
   : m_handle(_handle)
{
}

NetString NiXnetInterface::Name::get()
{
   return NiXnet::GetStringValue(m_handle, nxPropIntf_Name);
}

u32 NiXnetInterface::Number::get()
{
   return NiXnet::GetValue<u32>(m_handle, nxPropIntf_Num);
}

u32 NiXnetInterface::PortNumber::get()
{
   return NiXnet::GetValue<u32>(m_handle, nxPropIntf_PortNum);
}

NiXnetProtocol NiXnetInterface::Protocol::get()
{
   return static_cast<NiXnetProtocol>(NiXnet::GetValue<u32>(m_handle, nxPropIntf_Protocol));
}

NetString NiXnetInterface::ToString()
{
   return this->Name;
}
