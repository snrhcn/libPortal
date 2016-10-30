#ifndef IPV6FRAGMENTATIONHEADER_H_
#define IPV6FRAGMENTATIONHEADER_H_

#include "../Layer.h"

namespace Portal {

    class IPv6FragmentationHeader: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return IPv6FragmentationHeader::IPv6FragmentationHeaderConstFunc;
        };

        static Layer* IPv6FragmentationHeaderConstFunc() {
            return new IPv6FragmentationHeader;
        };

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldNextHeader = 0;
        static const byte FieldReserved = 1;
        static const byte FieldFragmentOffset = 2;
        static const byte FieldRes = 3;
        static const byte FieldMflag = 4;
        static const byte FieldIdentification = 5;

    public:

        enum { PROTO = 0x2c };

        IPv6FragmentationHeader();

        void SetNextHeader(const byte& value) {
            SetFieldValue(FieldNextHeader,value);
        };

        void SetReserved(const byte& value) {
            SetFieldValue(FieldReserved,value);
        };

        void SetFragmentOffset(const word& value) {
            SetFieldValue(FieldFragmentOffset,value);
        };

        void SetRes(const word& value) {
            SetFieldValue(FieldRes,value);
        };

        void SetMflag(const word& value) {
            SetFieldValue(FieldMflag,value);
        };

        void SetIdentification(const word& value) {
            SetFieldValue(FieldIdentification,value);
        };

        byte  GetNextHeader() const {
            return GetFieldValue<byte>(FieldNextHeader);
        };

        byte  GetReserved() const {
            return GetFieldValue<byte>(FieldReserved);
        };

        word  GetFragmentOffset() const {
            return GetFieldValue<word>(FieldFragmentOffset);
        };

        word  GetRes() const {
            return GetFieldValue<word>(FieldRes);
        };

        word  GetMflag() const {
            return GetFieldValue<word>(FieldMflag);
        };

        word  GetIdentification() const {
            return GetFieldValue<word>(FieldIdentification);
        };

        ~IPv6FragmentationHeader() { /* Destructor */ };

    };

}

#endif /* IPV6FRAGMENTATIONHEADER_H_ */
