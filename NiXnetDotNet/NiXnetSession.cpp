#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetSession::NiXnetSession(NetString _filenameOrAlias, NetString _clusterName, cli::array<NetString>^ _list, NetString _interface, NiXnetMode _mode)
{
   cli::pin_ptr<nxSessionRef_t> pointerToSession = &m_handle;
   std::string dbName(NiXnet::AsString(_filenameOrAlias));
   std::string cluster(NiXnet::AsString(_clusterName).c_str());
   std::string list(NiXnet::AsString(String::Join(",", _list)));
   std::string iface(NiXnet::AsString(_interface).c_str());
   u32 mode = static_cast<u32>(_mode);
   NiXnet::CheckStatus(nxCreateSession(dbName.c_str(), cluster.c_str(), list.c_str(), iface.c_str(), mode, pointerToSession));
}

void NiXnetSession::Start(NiXnetScope _scope)
{
   nxStart(m_handle, static_cast<u32>(_scope));
}

void NiXnetSession::Stop(NiXnetScope _scope)
{
   nxStop(m_handle, static_cast<u32>(_scope));
}

u32 NiXnetSession::NumberOfFramesOrSignals::get()
{
   return NiXnet::GetValue<u32>(m_handle, nxPropSession_NumInList);
}

cli::array<NetString>^ NiXnetSession::FramesOrSignals::get()
{
   NetString list = NiXnet::GetStringValue(m_handle, nxPropSession_List);
   return list->Split(',');
}

bool NiXnetSession::LinMaster::get()
{
   return NiXnet::GetValue<bool>(m_handle, nxPropSession_IntfLINMaster) != 0;
}

void NiXnetSession::LinMaster::set(bool _value)
{
   return NiXnet::SetValue<bool>(m_handle, nxPropSession_IntfLINMaster, _value);
}

cli::array<NetString>^ NiXnetSession::LinScheduleNames::get()
{
   return NiXnet::GetStringValue(m_handle, nxPropSession_IntfLINSchedNames)->Split(',');
}

/*
u32 NiXnetSession::LinScheduleIndex::get()
{
nxReadState(m_handle, nxState_LINScheduleChange, sizeof(u32));
}
*/

void NiXnetSession::LinScheduleIndex::set(u32 _value)
{
   NiXnet::CheckStatus(nxWriteState(m_handle, nxState_LINScheduleChange, sizeof(u32), &_value));
}

cli::array<System::Tuple<double, DateTime>^>^ NiXnetSession::ReadSignalSinglePoint()
{
   cli::array<System::Tuple<double, DateTime>^>^ ret = gcnew cli::array<System::Tuple<double, DateTime>^>(this->NumberOfFramesOrSignals);
   f64* values = new f64[ret->Length];
   nxTimestamp_t* timestamps = new nxTimestamp_t[ret->Length];
   try
   {
      NiXnet::CheckStatus(nxReadSignalSinglePoint(m_handle, values, sizeof(f64) * ret->Length, timestamps, sizeof(nxTimestamp_t) * ret->Length));

      for (int i = 0; i < ret->Length; i++)
      {
         DateTime timestamp(timestamps[i], DateTimeKind::Utc);
         ret[i] = Tuple::Create(values[i], timestamp);
      }
      return ret;
   }
   finally
   {
      delete[] values;
      delete[] timestamps;
   }
}

NiXnetSession::~NiXnetSession()
{
   NiXnet::CheckStatus(nxClear(m_handle));
}
