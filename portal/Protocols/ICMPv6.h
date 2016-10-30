#ifndef ICMPV6_H_
#define ICMPV6_H_

#include "ICMPv6Layer.h"

namespace Portal {

    class ICMPv6: public ICMPv6Layer {

        void DefineProtocol();

		byte MapTypeNumber(short_word type);

        Constructor GetConstructor() const {
            return ICMPv6::ICMPv6ConstFunc;
        };

        static Layer* ICMPv6ConstFunc() {
            return new ICMPv6;
        };

        void Portal();

        std::string MatchFilter() const ;

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldRestOfHeader = 3;
        static const byte FieldMTU = 4;
        static const byte FieldPointer = 5;
        static const byte FieldIdentifier = 6;
        static const byte FieldSequenceNumber = 7;
        static const byte FieldLength = 8;

    public:

        enum { PROTO = 0x3A01 };

		/* ------- Messages types --------- */

		/* +++ Error messages +++ */
		static const byte DestinationUnreachable;
		static const byte TimeExceeded;
		static const byte ParameterProblem;
		static const byte PacketTooBig;

		/* +++ Request and replies +++ */
		static const byte EchoRequest;
		static const byte EchoReply;

        ICMPv6();

        void SetRestOfHeader(const word& value) {
            SetFieldValue(FieldRestOfHeader,value);
        };

        void SetMTU(const word& value) {
            SetFieldValue(FieldMTU,value);
        };

        void SetPointer(const word& value) {
            SetFieldValue(FieldPointer,value);
        };

        void SetIdentifier(const short_word& value) {
            SetFieldValue(FieldIdentifier,value);
        };

        void SetSequenceNumber(const short_word& value) {
            SetFieldValue(FieldSequenceNumber,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        word  GetRestOfHeader() const {
            return GetFieldValue<word>(FieldRestOfHeader);
        };

        word  GetMTU() const {
            return GetFieldValue<word>(FieldMTU);
        };

        word  GetPointer() const {
            return GetFieldValue<word>(FieldPointer);
        };

        short_word  GetIdentifier() const {
            return GetFieldValue<short_word>(FieldIdentifier);
        };

        short_word  GetSequenceNumber() const {
            return GetFieldValue<short_word>(FieldSequenceNumber);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        ~ICMPv6() { /* Destructor */ };

    };

}

#endif /* ICMPV6_H_ */
