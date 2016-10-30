#ifndef IPOPTIONPAD_H_
#define IPOPTIONPAD_H_

#include "IPOptionLayer.h"

namespace Portal {

    class IPOptionPad: public IPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return IPOptionPad::IPOptionPadConstFunc;
        };

        static Layer* IPOptionPadConstFunc() {
            return new IPOptionPad;
        };

        void Portal();

        void ReDefineActiveFields();

        static const byte FieldCopyFlag = 0;
        static const byte FieldClass = 1;
        static const byte FieldOption = 2;

    public:

        enum { PROTO = 0x5001 };

        IPOptionPad();

        void SetCopyFlag(const word& value) {
            SetFieldValue(FieldCopyFlag,value);
        };

        void SetClass(const word& value) {
            SetFieldValue(FieldClass,value);
        };

        void SetOption(const word& value) {
            SetFieldValue(FieldOption,value);
        };

        void SetLength(const byte& value) { /* NO length */ };

        word  GetCopyFlag() const {
            return GetFieldValue<word>(FieldCopyFlag);
        };

        word  GetClass() const {
            return GetFieldValue<word>(FieldClass);
        };

        word  GetOption() const {
            return GetFieldValue<word>(FieldOption);
        };

        byte  GetLength() const { return 1; }

        ~IPOptionPad() { /* Destructor */ };

    };

}

#endif /* IPOPTIONPAD_H_ */
