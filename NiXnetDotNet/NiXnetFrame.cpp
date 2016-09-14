#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetFrame::NiXnetFrame(nxDatabaseRef_t _handle)
   : m_handle(_handle)
{
}

NetString NiXnetFrame::Name::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropFrm_Name);
}

u32 NiXnetFrame::Identifier::get()
{
   return NiXnet::GetDbValue<u32>(m_handle, nxPropFrm_ID);
}

cli::array<NiXnetSignal^>^ NiXnetFrame::Signals::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropFrm_SigRefs);
   cli::array<NiXnetSignal^>^ signals = gcnew cli::array<NiXnetSignal^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      signals[i] = gcnew NiXnetSignal(handles[i]);
   }
   return signals;
}

NetString NiXnetFrame::ToString()
{
   return this->Name;
}
