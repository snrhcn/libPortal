#ifndef TCP_H_
#define TCP_H_

#include "../Layer.h"

namespace Portal {

    class TCP: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return TCP::TCPConstFunc;
        };

        static Layer* TCPConstFunc() {
            return new TCP;
        };

        void Portal();

        std::string MatchFilter() const ;

        void ParseLayerData(ParseInfo* info);

        static const byte FieldSrcPort = 0;
        static const byte FieldDstPort = 1;
        static const byte FieldSeqNumber = 2;
        static const byte FieldAckNumber = 3;
        static const byte FieldDataOffset = 4;
        static const byte FieldReserved = 5;
        static const byte FieldFlags = 6;
        static const byte FieldWindowsSize = 7;
        static const byte FieldCheckSum = 8;
        static const byte FieldUrgPointer = 9;

    public:

		enum { PROTO = 0x06 };

		/* Flags */
		static const byte FIN;
		static const byte SYN;
		static const byte RST;
		static const byte PSH;
		static const byte ACK;
		static const byte URG;
		static const byte ECE;
		static const byte CWR;

		/* Flag Checkers */
		byte GetFIN() { return (GetFlags() & TCP::FIN); };
		byte GetSYN() { return (GetFlags() & TCP::SYN); };
		byte GetRST() { return (GetFlags() & TCP::RST); };
		byte GetPSH() { return (GetFlags() & TCP::PSH); };
		byte GetACK() { return (GetFlags() & TCP::ACK); };
		byte GetURG() { return (GetFlags() & TCP::URG); };
		byte GetECE() { return (GetFlags() & TCP::ECE); };
		byte GetCWR() { return (GetFlags() & TCP::CWR); };

        TCP();

        void SetSrcPort(const short_word& value) {
            SetFieldValue(FieldSrcPort,value);
        };

        void SetDstPort(const short_word& value) {
            SetFieldValue(FieldDstPort,value);
        };

        void SetSeqNumber(const word& value) {
            SetFieldValue(FieldSeqNumber,value);
        };

        void SetAckNumber(const word& value) {
            SetFieldValue(FieldAckNumber,value);
        };

        void SetDataOffset(const word& value) {
            SetFieldValue(FieldDataOffset,value);
        };

        void SetReserved(const word& value) {
            SetFieldValue(FieldReserved,value);
        };

        void SetFlags(const byte& value) {
            SetFieldValue(FieldFlags,value);
        };

        void SetWindowsSize(const short_word& value) {
            SetFieldValue(FieldWindowsSize,value);
        };

        void SetCheckSum(const short_word& value) {
            SetFieldValue(FieldCheckSum,value);
        };

        void SetUrgPointer(const short_word& value) {
            SetFieldValue(FieldUrgPointer,value);
        };

        short_word  GetSrcPort() const {
            return GetFieldValue<short_word>(FieldSrcPort);
        };

        short_word  GetDstPort() const {
            return GetFieldValue<short_word>(FieldDstPort);
        };

        word  GetSeqNumber() const {
            return GetFieldValue<word>(FieldSeqNumber);
        };

        word  GetAckNumber() const {
            return GetFieldValue<word>(FieldAckNumber);
        };

        word  GetDataOffset() const {
            return GetFieldValue<word>(FieldDataOffset);
        };

        word  GetReserved() const {
            return GetFieldValue<word>(FieldReserved);
        };

        byte  GetFlags() const {
            return GetFieldValue<byte>(FieldFlags);
        };

        short_word  GetWindowsSize() const {
            return GetFieldValue<short_word>(FieldWindowsSize);
        };

        short_word  GetCheckSum() const {
            return GetFieldValue<short_word>(FieldCheckSum);
        };

        short_word  GetUrgPointer() const {
            return GetFieldValue<short_word>(FieldUrgPointer);
        };

        ~TCP() { /* Destructor */ };

        /* Return the size of the following TCPOptions */
        size_t ComputeOptionSize() const;

    };

}

#endif /* TCP_H_ */
