// This is the main DLL file.

#include "stdafx.h"

#include "NiXnetDotNet.h"
#include "nixnet.h"

using namespace NiXnetDotNet;

void NiXnet::CheckStatus(nxStatus_t _status)
{
   if (_status != nxSuccess)
   {
      char errorDescription[2048];
      nxStatusToString(_status, 2048, errorDescription);
      throw gcnew InvalidOperationException(gcnew String(errorDescription));
   }
}

NetString NiXnet::GetStringValue(nxSessionRef_t _handle, u32 _propertyId)
{
   u32 propSize;
   NiXnet::CheckStatus(nxGetPropertySize(_handle, _propertyId, &propSize));
   char *stringValue = new char[propSize];
   NiXnet::CheckStatus(nxGetProperty(_handle, _propertyId, propSize, stringValue));
   System::String^ ret = gcnew System::String(stringValue);
   delete[] stringValue;
   return ret;
}

generic<typename T> T NiXnet::GetValue(nxSessionRef_t _handle, u32 _propertyId)
{
   T value;
   NiXnet::CheckStatus(nxGetProperty(_handle, _propertyId, sizeof(T), &value));
   return value;
}

generic<typename T> void NiXnet::SetValue(nxSessionRef_t _handle, u32 _propertyId, T _value)
{
   NiXnet::CheckStatus(nxSetProperty(_handle, _propertyId, sizeof(T), &_value));
}

generic<typename T> cli::array<T>^ NiXnet::GetArrayValue(nxSessionRef_t _handle, u32 _propertyId)
{
   u32 propSize;
   NiXnet::CheckStatus(nxGetPropertySize(_handle, _propertyId, &propSize));

   cli::array<T> ^ ret = gcnew cli::array<T>(propSize / sizeof(T));
   if (ret->Length > 0)
   {
      cli::pin_ptr<T> firstItem = &ret[0];
      NiXnet::CheckStatus(nxGetProperty(_handle, _propertyId, propSize, firstItem));
   }
   return ret;
}

NetString NiXnet::GetDbStringValue(nxDatabaseRef_t _handle, u32 _propertyId)
{
   u32 propSize;
   NiXnet::CheckStatus(nxdbGetPropertySize(_handle, _propertyId, &propSize));
   char *stringValue = new char[propSize];
   NiXnet::CheckStatus(nxdbGetProperty(_handle, _propertyId, propSize, stringValue));
   System::String^ ret = gcnew System::String(stringValue);
   delete[] stringValue;
   return ret;
}


generic<typename T> T NiXnet::GetDbValue(nxDatabaseRef_t _handle, u32 _propertyId)
{
   T value;
   NiXnet::CheckStatus(nxdbGetProperty(_handle, _propertyId, sizeof(T), &value));
   return value;
}

generic<typename T> cli::array<T>^ NiXnet::GetDbArrayValue(nxDatabaseRef_t _handle, u32 _propertyId)
{
   u32 propSize;
   NiXnet::CheckStatus(nxdbGetPropertySize(_handle, _propertyId, &propSize));

   cli::array<T> ^ ret = gcnew cli::array<T>(propSize / sizeof(T));
   if (ret->Length > 0)
   {
      cli::pin_ptr<T> firstItem = &ret[0];
      NiXnet::CheckStatus(nxdbGetProperty(_handle, _propertyId, propSize, firstItem));
   }
   return ret;
}
std::string NiXnet::AsString(NetString _string)
{
   IntPtr p = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(_string);
   char *pNewCharStr = static_cast<char*>(p.ToPointer());
   std::string ret(pNewCharStr);
   System::Runtime::InteropServices::Marshal::FreeHGlobal(p);
   return ret;
}
