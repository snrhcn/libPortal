#ifndef TCPOPTIONMAXSEGSIZE_H_
#define TCPOPTIONMAXSEGSIZE_H_

#include "TCPOptionLayer.h"

namespace Portal {

    class TCPOptionMaxSegSize: public TCPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return TCPOptionMaxSegSize::TCPOptionMaxSegSizeConstFunc;
        };

        static Layer* TCPOptionMaxSegSizeConstFunc() {
            return new TCPOptionMaxSegSize;
        };

        void Portal();

        void ReDefineActiveFields();

        static const byte FieldKind = 0;
        static const byte FieldLength = 1;
        static const byte FieldMaxSegSize = 2;

    public:

        enum { PROTO = 0x9001 };

        TCPOptionMaxSegSize();

        void SetKind(const byte& value) {
            SetFieldValue(FieldKind,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        void SetMaxSegSize(const short_word& value) {
            SetFieldValue(FieldMaxSegSize,value);
        };

        byte  GetKind() const {
            return GetFieldValue<byte>(FieldKind);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        short_word  GetMaxSegSize() const {
            return GetFieldValue<short_word>(FieldMaxSegSize);
        };

        ~TCPOptionMaxSegSize() { /* Destructor */ };

    };

}

#endif /* TCPOPTIONMAXSEGSIZE_H_ */
