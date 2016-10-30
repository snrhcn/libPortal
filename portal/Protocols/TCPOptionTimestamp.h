#ifndef TCPOPTIONTIMESTAMP_H_
#define TCPOPTIONTIMESTAMP_H_

#include "TCPOptionLayer.h"

namespace Portal {

    class TCPOptionTimestamp: public TCPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return TCPOptionTimestamp::TCPOptionTimestampConstFunc;
        };

        static Layer* TCPOptionTimestampConstFunc() {
            return new TCPOptionTimestamp;
        };

        void Portal();

        void ReDefineActiveFields();

        static const byte FieldKind = 0;
        static const byte FieldLength = 1;
        static const byte FieldValue = 2;
        static const byte FieldEchoReply = 3;

    public:

        enum { PROTO = 0x9002 };

        TCPOptionTimestamp();

        void SetKind(const byte& value) {
            SetFieldValue(FieldKind,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        void SetValue(const word& value) {
            SetFieldValue(FieldValue,value);
        };

        void SetEchoReply(const word& value) {
            SetFieldValue(FieldEchoReply,value);
        };

        byte  GetKind() const {
            return GetFieldValue<byte>(FieldKind);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        word  GetValue() const {
            return GetFieldValue<word>(FieldValue);
        };

        word  GetEchoReply() const {
            return GetFieldValue<word>(FieldEchoReply);
        };

        ~TCPOptionTimestamp() { /* Destructor */ };

    };

}

#endif /* TCPOPTIONTIMESTAMP_H_ */
