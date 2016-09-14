#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetDataBase::NiXnetDataBase(NetString _filenameOrAlias)
{
   cli::pin_ptr<nxDatabaseRef_t> pointerToDatabase = &m_handle;
   NiXnet::CheckStatus(nxdbOpenDatabase(NiXnet::AsString(_filenameOrAlias).c_str(), pointerToDatabase));
}

cli::array<NiXnetCluster^>^ NiXnetDataBase::Clusters::get()
{
   cli::array<nxDatabaseRef_t>^ handles = NiXnet::GetDbArrayValue<nxDatabaseRef_t>(m_handle, nxPropDatabase_ClstRefs);
   cli::array<NiXnetCluster^>^ clusters = gcnew cli::array<NiXnetCluster^>(handles->Length);
   for (int i = 0; i < handles->Length; i++)
   {
      clusters[i] = gcnew NiXnetCluster(handles[i]);
   }
   return clusters;
}

NiXnetDataBase::~NiXnetDataBase()
{
   NiXnet::CheckStatus(nxdbCloseDatabase(m_handle, 0));
}
