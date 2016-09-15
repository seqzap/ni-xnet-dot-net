#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetLinSchedule::NiXnetLinSchedule(u32 _handle)
   : m_handle(_handle)
{
}

NetString NiXnetLinSchedule::Name::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropLINSched_Name);
}

NetString NiXnetLinSchedule::Priority::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropLINSched_Priority);
}

NiXnetLinScheduleRunMode NiXnetLinSchedule::RunMode::get()
{
   return static_cast<NiXnetLinScheduleRunMode>(NiXnet::GetDbValue<u32>(m_handle, nxPropLINSched_RunMode));
}

NetString NiXnetLinSchedule::ToString()
{
   return this->Name;
}
