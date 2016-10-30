#ifndef IPOPTION_H_
#define IPOPTION_H_

#include "IPOptionLayer.h"
#include "IPOptionPad.h"

namespace Portal {

    class IPOption: public IPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return IPOption::IPOptionConstFunc;
        };

        static Layer* IPOptionConstFunc() {
            return new IPOption;
        };

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldCopyFlag = 0;
        static const byte FieldClass = 1;
        static const byte FieldOption = 2;
        static const byte FieldLength = 3;

    public:

        enum { PROTO = 0x5000 };

        /* Padding layers */
        static const IPOptionPad NOP;
        static const IPOptionPad EOL;

        IPOption();

        void SetCopyFlag(const word& value) {
            SetFieldValue(FieldCopyFlag,value);
        };

        void SetClass(const word& value) {
            SetFieldValue(FieldClass,value);
        };

        void SetOption(const word& value) {
            SetFieldValue(FieldOption,value);
        };

        void SetLength(const byte& value) {
            SetFieldValue(FieldLength,value);
        };

        word  GetCopyFlag() const {
            return GetFieldValue<word>(FieldCopyFlag);
        };

        word  GetClass() const {
            return GetFieldValue<word>(FieldClass);
        };

        word  GetOption() const {
            return GetFieldValue<word>(FieldOption);
        };

        byte  GetLength() const {
            return GetFieldValue<byte>(FieldLength);
        };

        ~IPOption() { /* Destructor */ };

    };

}

#endif /* IPOPTION_H_ */
