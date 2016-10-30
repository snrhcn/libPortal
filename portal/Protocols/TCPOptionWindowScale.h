#ifndef TCPOPTIONWSCALE_H_
#define TCPOPTIONWSCALE_H_

#include "TCPOptionLayer.h"

namespace Portal {

    class TCPOptionWindowScale: public TCPOptionLayer {

        Constructor GetConstructor() const {
            return TCPOptionWindowScale::TCPOptionWindowScaleConstFunc;
        };

        static Layer* TCPOptionWindowScaleConstFunc() {
            return new TCPOptionWindowScale;
        };

        void DefineProtocol();

        void Portal();

        void ReDefineActiveFields();

        static const byte FieldKind = 0;
        static const byte FieldLength = 1;
        static const byte FieldShift = 2;

    public:

        TCPOptionWindowScale();

        enum { PROTO = 0x9008 };

        void SetKind(const byte& value) {
            SetFieldValue(FieldKind,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        void SetShift(const byte& value) {
            SetFieldValue(FieldShift,value);
        };

        byte  GetKind() const {
            return GetFieldValue<byte>(FieldKind);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        byte  GetShift() const {
            return GetFieldValue<byte>(FieldShift);
        };

        ~TCPOptionWindowScale() { /* Destructor */ };

    };
}

#endif /* TCPOPTIONWSCALE */

