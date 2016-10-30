#ifndef ICMP_H_
#define ICMP_H_

#include "../Layer.h"
#include "ICMPLayer.h"

namespace Portal {

    class ICMP: public ICMPLayer {

        void DefineProtocol();

		byte MapTypeNumber(short_word type);

        Constructor GetConstructor() const {
            return ICMP::ICMPConstFunc;
        };

        static Layer* ICMPConstFunc() {
            return new ICMP;
        };

        void Portal();

        std::string MatchFilter() const ;

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldType = 0;
        static const byte FieldCode = 1;
        static const byte FieldCheckSum = 2;
        static const byte FieldRestOfHeader = 3;
        static const byte FieldIdentifier = 4;
        static const byte FieldSequenceNumber = 5;
        static const byte FieldPointer = 6;
        static const byte FieldGateway = 7;
        static const byte FieldLength = 8;
        static const byte FieldMTUNextHop = 9;

    public:

		enum { PROTO = 0x01 };

		/* ------- Messages types --------- */

		/* +++ Other +++ */
		static const byte SourceQuench;
		static const byte EchoRedirect;

		/* +++ Error messages +++ */
		static const byte DestinationUnreachable;
		static const byte TimeExceeded;
		static const byte ParameterProblem;

		/* +++ Request and replies +++ */
		static const byte EchoRequest;
		static const byte EchoReply;

		static const byte TimeStampRequest;
		static const byte TimeStampReply;

		static const byte InformationRequest;
		static const byte InformationReply;

		static const byte AddressMaskRequest;
		static const byte AddressMaskReply;

        ICMP();

        void SetType(const byte& value) {
            SetFieldValue(FieldType,value);
        };

        void SetCode(const byte& value) {
            SetFieldValue(FieldCode,value);
        };

        void SetCheckSum(const short_word& value) {
            SetFieldValue(FieldCheckSum,value);
        };

        void SetRestOfHeader(const word& value) {
            SetFieldValue(FieldRestOfHeader,value);
        };

        void SetIdentifier(const short_word& value) {
            SetFieldValue(FieldIdentifier,value);
        };

        void SetSequenceNumber(const short_word& value) {
            SetFieldValue(FieldSequenceNumber,value);
        };

        void SetPointer(const byte& value) {
            SetFieldValue(FieldPointer,value);
        };

        void SetGateway(const std::string& value) {
            SetFieldValue(FieldGateway,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        void SetMTU(const short_word& value) {
            SetFieldValue(FieldMTUNextHop,value);
        };

        byte  GetType() const {
            return GetFieldValue<byte>(FieldType);
        };

        byte  GetCode() const {
            return GetFieldValue<byte>(FieldCode);
        };

        short_word  GetCheckSum() const {
            return GetFieldValue<short_word>(FieldCheckSum);
        };

        word  GetRestOfHeader() const {
            return GetFieldValue<word>(FieldRestOfHeader);
        };

        short_word  GetIdentifier() const {
            return GetFieldValue<short_word>(FieldIdentifier);
        };

        short_word  GetSequenceNumber() const {
            return GetFieldValue<short_word>(FieldSequenceNumber);
        };

        byte  GetPointer() const {
            return GetFieldValue<byte>(FieldPointer);
        };

        std::string  GetGateway() const {
            return GetFieldValue<std::string>(FieldGateway);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        short_word GetMTU() {
        	return GetFieldValue<short_word>(FieldMTUNextHop);
        };

        ~ICMP() { /* Destructor */ };

    };

}

#endif /* ICMP_H_ */
