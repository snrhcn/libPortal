#ifndef IPOPTIONLSRR_H_
#define IPOPTIONLSRR_H_

#include "IPOptionLayer.h"

namespace Portal {

    class IPOptionPointer: public IPOptionLayer {

    protected:

        void DefineProtocol();

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldCopyFlag = 0;
        static const byte FieldClass = 1;
        static const byte FieldOption = 2;
        static const byte FieldLength = 3;
        static const byte FieldPointer = 4;

    public:

        IPOptionPointer() { /* */ };

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

        void SetPointer(const byte& value) {
            SetFieldValue(FieldPointer,value);
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

        byte  GetPointer() const {
            return GetFieldValue<byte>(FieldPointer);
        };

        virtual ~IPOptionPointer() { /* Destructor */ };

    };

    class IPOptionLSRR : public IPOptionPointer {

    	Constructor GetConstructor() const {
            return IPOptionLSRR::IPOptionLSRRConstFunc;
        };

        static Layer* IPOptionLSRRConstFunc() {
            return new IPOptionLSRR;
        };

    public:

        IPOptionLSRR();

        enum { PROTO = 0x5003 };

        ~IPOptionLSRR() { /* Destructor */ };
    };

    class IPOptionRR : public IPOptionPointer {

    	Constructor GetConstructor() const {
            return IPOptionRR::IPOptionRRConstFunc;
        };

        static Layer* IPOptionRRConstFunc() {
            return new IPOptionRR;
        };

    public:

        IPOptionRR();

        enum { PROTO = 0x5004 };

        ~IPOptionRR() { /* Destructor */ };

    };

    class IPOptionSSRR : public IPOptionPointer {

    	Constructor GetConstructor() const {
            return IPOptionSSRR::IPOptionSSRRConstFunc;
        };

        static Layer* IPOptionSSRRConstFunc() {
            return new IPOptionSSRR;
        };

    public:

        IPOptionSSRR();

        enum { PROTO = 0x5005 };

        ~IPOptionSSRR() { /* Destructor */ };

    };
}

#endif /* IPOPTIONLSRR_H_ */
