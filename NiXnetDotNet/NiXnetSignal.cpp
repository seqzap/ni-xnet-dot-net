#include "Stdafx.h"
#include "NiXnetDotNet.h"

using namespace NiXnetDotNet;

NiXnetSignal::NiXnetSignal(nxDatabaseRef_t _handle)
   : m_handle(_handle)
{
}

NetString NiXnetSignal::Name::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropSig_Name);
}

NetString NiXnetSignal::UniqueName::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropSig_NameUniqueToCluster);
}

NiXnetByteOrder NiXnetSignal::ByteOrder::get()
{

   return static_cast<NiXnetByteOrder>(NiXnet::GetDbValue<u32>(m_handle, nxPropSig_ByteOrdr));
}

NiXnetDataType NiXnetSignal::DataType::get()
{
   return static_cast<NiXnetDataType>(NiXnet::GetDbValue<u32>(m_handle, nxPropSig_DataType));
}

double NiXnetSignal::DefaultValue::get()
{
   return NiXnet::GetDbValue<double>(m_handle, nxPropSig_Default);
}

double NiXnetSignal::MaximumValue::get()
{
   return NiXnet::GetDbValue<double>(m_handle, nxPropSig_Max);
}

double NiXnetSignal::MinimumValue::get()
{
   return NiXnet::GetDbValue<double>(m_handle, nxPropSig_Min);
}

u32 NiXnetSignal::StartBit::get()
{
   return NiXnet::GetDbValue<u32>(m_handle, nxPropSig_StartBit);
}

u32 NiXnetSignal::NumberOfBits::get()
{
   return NiXnet::GetDbValue<u32>(m_handle, nxPropSig_NumBits);
}

double NiXnetSignal::ScalingFactor::get()
{
   return NiXnet::GetDbValue<double>(m_handle, nxPropSig_ScaleFac);
}

double NiXnetSignal::ScalingOffset::get()
{
   return NiXnet::GetDbValue<double>(m_handle, nxPropSig_ScaleOff);
}

NetString NiXnetSignal::Unit::get()
{
   return NiXnet::GetDbStringValue(m_handle, nxPropSig_Unit);
}

NetString NiXnetSignal::ToString()
{
   return this->Name;
}
