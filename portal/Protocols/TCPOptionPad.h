#ifndef TCPOPTIONPAD_H_
#define TCPOPTIONPAD_H_

#include "TCPOptionLayer.h"

namespace Portal {

    class TCPOptionPad: public TCPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return TCPOptionPad::TCPOptionPadConstFunc;
        };

        static Layer* TCPOptionPadConstFunc() {
            return new TCPOptionPad;
        };

        void Portal();

        void ReDefineActiveFields();

        static const byte FieldKind = 0;

    public:

        enum { PROTO = 0x9003 };

        TCPOptionPad();

        void SetKind(const byte& value) {
            SetFieldValue(FieldKind,value);
        };

        void SetLength(const byte& value) {  /*  */ };

        byte  GetKind() const {
            return GetFieldValue<byte>(FieldKind);
        };

        byte  GetLength() const {
            return 1;
        };

        ~TCPOptionPad() { /* Destructor */ };

    };

}

#endif /* TCPOPTIONPAD_H_ */
