// NiXnetDotNet.h

#include <string>
#include "nixnet.h"

#pragma once

using namespace System;

typedef System::String^ NetString;

namespace NiXnetDotNet {

   public ref class NiXnet
   {
   internal:
      static void CheckStatus(nxStatus_t _status);

      generic <typename T> static T GetValue(nxSessionRef_t _handle, u32 _propertyId);
      generic <typename T> static void SetValue(nxSessionRef_t _handle, u32 _propertyId, T _value);

      static NetString GetStringValue(nxSessionRef_t _handle, u32 _propertyId);

      generic <typename T> static cli::array<T>^ GetArrayValue(nxSessionRef_t _handle, u32 _propertyId);

      generic <typename T> static T GetDbValue(nxDatabaseRef_t _handle, u32 _propertyId);

      static NetString GetDbStringValue(nxDatabaseRef_t _handle, u32 _propertyId);

      generic <typename T> static cli::array<T>^ GetDbArrayValue(nxDatabaseRef_t _handle, u32 _propertyId);

      static std::string AsString(NetString);
   };

   public enum class NiXnetProtocol : u32
   {
      CAN = nxProtocol_CAN,
      FlexRay = nxProtocol_FlexRay,
      LIN = nxProtocol_LIN,
   };

   public enum class NiXnetLinProtocolVersion : u32
   {
      Ver_1_2 = nxLINProtocolVer_1_2,
      Ver_1_3 = nxLINProtocolVer_1_3,
      Ver_2_0 = nxLINProtocolVer_2_0,
      Ver_2_1 = nxLINProtocolVer_2_1,
   };

   public enum class NiXnetByteOrder : u32
   {
      LittleEndian = nxSigByteOrdr_LittleEndian,
      BigEndian = nxSigByteOrdr_BigEndian,
   };

   public enum class NiXnetMode : u32
   {
      SignalInSinglePoint = nxMode_SignalInSinglePoint,
      SignalOutSinglePoint = nxMode_SignalOutSinglePoint,
      SignalInWaveform = nxMode_SignalInWaveform,
      SignalOutWaveform = nxMode_SignalOutWaveform,
      SignalInXY = nxMode_SignalInXY,
      SignalOutXY = nxMode_SignalOutXY,
      FrameInStream = nxMode_FrameInStream,
      FrameOutStream = nxMode_FrameOutStream,
      FrameInQueued = nxMode_FrameInQueued,
      FrameOutQueued = nxMode_FrameOutQueued,
      FrameInSinglePoint = nxMode_FrameInSinglePoint,
      FrameOutSinglePoint = nxMode_FrameOutSinglePoint,
      SignalConversionSinglePoint = nxMode_SignalConversionSinglePoint,
   };

   public enum class NiXnetDataType : u32
   {
      Signed = nxSigDataType_Signed,
      Unsigned = nxSigDataType_Unsigned,
      IEEEFloat = nxSigDataType_IEEEFloat,
   };

   public enum class NiXnetScope : u32
   {
      Normal = nxStartStop_Normal,
      SessionOnly = nxStartStop_SessionOnly,
      InterfaceOnly = nxStartStop_InterfaceOnly,
      SessionOnlyBlocking = nxStartStop_SessionOnlyBlocking,
   };

   public enum class NiXnetLinScheduleRunMode : u32
   {
      Continous = nxLINSchedRunMode_Continuous,
      Once = nxLINSchedRunMode_Once,
      Null = nxLINSchedRunMode_Null,
   };

   public ref class NiXnetInterface
   {
   private:
      u32 m_handle;

   internal:
      NiXnetInterface(u32 _handle);

   public:
      property NetString Name { NetString get(); }
      property u32 Number { u32 get(); }
      property u32 PortNumber { u32 get(); }
      property NiXnetProtocol Protocol { NiXnetProtocol get(); }

      virtual NetString ToString() override;
   };

   public ref class NiXnetDevice
   {
   private:
      u32 m_handle;

   internal:
      NiXnetDevice(u32 _handle);

   public:
      property NetString ProductName { NetString get(); }
      property u32 ProductNumber { u32 get(); }
      property u32 SerialNumber { u32 get(); }
      property cli::array<NiXnetInterface^>^ Interfaces { cli::array<NiXnetInterface^>^ get(); }

      virtual NetString ToString() override;
   };

   public ref class NiXnetSystem
   {
   private:
      nxSessionRef_t m_session;

   public:
      NiXnetSystem();
      cli::array<NiXnetDevice^>^ ListDevices();
      property cli::array<NiXnetInterface^>^ Interfaces{ cli::array<NiXnetInterface^>^ get(); }
      ~NiXnetSystem();
   };

   public ref class NiXnetSignal
   {
   private:
      nxDatabaseRef_t m_handle;

   internal:
      NiXnetSignal(nxDatabaseRef_t _handle);

   public:
      property NetString Name { NetString get();  }
      property NetString UniqueName { NetString get();  }
      property NiXnetByteOrder ByteOrder { NiXnetByteOrder get();  }
      property NiXnetDataType DataType { NiXnetDataType get();  }
      property double DefaultValue { double get();  }
      property double MaximumValue { double get();  }
      property double MinimumValue { double get();  }
      property u32 StartBit { u32 get();  }
      property u32 NumberOfBits { u32 get();  }
      property double ScalingFactor { double get();  }
      property double ScalingOffset { double get();  }
      property NetString Unit { NetString get();  }
      virtual NetString ToString() override;
   };

   public ref class NiXnetFrame
   {
   private:
      nxDatabaseRef_t m_handle;

   internal:
      NiXnetFrame(nxDatabaseRef_t _handle);

   public:
      property NetString Name { NetString get();  }
      property u32 Identifier { u32 get();  }
      property cli::array<NiXnetSignal^>^ Signals { cli::array<NiXnetSignal^>^ get(); }
      virtual NetString ToString() override;
   };

   public ref class NiXnetEcu
   {
   private:
      nxDatabaseRef_t m_handle;

   internal:
      NiXnetEcu(nxDatabaseRef_t _handle);

   public:
      property NetString Name { NetString get();  }
      property cli::array<NiXnetFrame^>^ FramesReceived { cli::array<NiXnetFrame^>^ get(); }
      property cli::array<NiXnetFrame^>^ FramesTansmitted { cli::array<NiXnetFrame^>^ get(); }
      property bool LinMaster { bool get();  }
      property NiXnetLinProtocolVersion LinVersion { NiXnetLinProtocolVersion get();  }
      virtual NetString ToString() override;
   };

   public ref class NiXnetLinSchedule
   {
   private:
      u32 m_handle;

   internal:
      NiXnetLinSchedule(u32 _handle);

   public:
      property NetString Name { NetString get(); }
      property NetString Priority { NetString get(); }
      property NiXnetLinScheduleRunMode RunMode{ NiXnetLinScheduleRunMode get();  }
      virtual NetString ToString() override;
   };

   public ref class NiXnetCluster
   {
   private:
      nxDatabaseRef_t m_handle;

   internal:
      NiXnetCluster(nxDatabaseRef_t _handle);

   public:
      property NetString Name { NetString get(); }
      property NiXnetProtocol Protocol { NiXnetProtocol get(); }
      property cli::array<NiXnetEcu^>^ Ecus { cli::array<NiXnetEcu^>^ get(); }
      property cli::array<NiXnetFrame^>^ Frames { cli::array<NiXnetFrame^>^ get(); }
      property cli::array<NiXnetSignal^>^ Signals { cli::array<NiXnetSignal^>^ get(); }
      property cli::array<NiXnetLinSchedule^>^ LinSchedules { cli::array<NiXnetLinSchedule^>^ get(); }
      virtual NetString ToString() override;
   };

   public ref class NiXnetDataBase
   {
   private:
      nxDatabaseRef_t m_handle;

   public:
      NiXnetDataBase(NetString _filenameOrAlias);
      property cli::array<NiXnetCluster^>^ Clusters { cli::array<NiXnetCluster^>^ get(); }
      ~NiXnetDataBase();
   };


   public ref class NiXnetSession
   {
   private:
      nxSessionRef_t m_handle;

   public:
      NiXnetSession(NetString _filenameOrAlias, NetString _clusterName, cli::array<NetString>^ _list, NetString _interface, NiXnetMode _mode);
      void Start(NiXnetScope _scope);
      void Stop(NiXnetScope _scope);
      property u32 NumberOfFramesOrSignals { u32 get();  }
      property cli::array<NetString>^ FramesOrSignals { cli::array<NetString>^ get(); }
      property bool LinMaster { bool get(); void set(bool); }
      property cli::array<NetString>^ LinScheduleNames { cli::array<NetString>^ get(); }
      property u32 LinScheduleIndex { void set(u32); }
      cli::array<System::Tuple<double, DateTime>^>^ ReadSignalSinglePoint();

      ~NiXnetSession();
   };
}
