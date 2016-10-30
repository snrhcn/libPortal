#ifndef SLL_H_
#define SLL_H_

#include "../Layer.h"

namespace Portal {

    class SLL: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return SLL::SLLConstFunc;
        };

        static Layer* SLLConstFunc() {
            return new SLL;
        };

        void Portal();

        void ReDefineActiveFields();

		void ParseLayerData(ParseInfo* info);

        static const byte FieldPackeType = 0;
        static const byte FieldAddressType = 1;
        static const byte FieldAddressLength = 2;
        static const byte FieldSourceAddress = 3;
        static const byte FieldPad = 4;
        static const byte FieldProtocol = 5;

    public:

		enum { PROTO = 0xfff0 };

        SLL();

        void SetPackeType(const short_word& value) {
            SetFieldValue(FieldPackeType,value);
        };

        void SetAddressType(const short_word& value) {
            SetFieldValue(FieldAddressType,value);
        };

        void SetAddressLength(const short_word& value) {
            SetFieldValue(FieldAddressLength,value);
        };

        void SetSourceAddress(const std::string& value) {
            SetFieldValue(FieldSourceAddress,value);
        };

        void SetPad(const std::vector<byte> & value) {
            SetFieldValue(FieldPad,value);
        };

        void SetProtocol(const short_word& value) {
            SetFieldValue(FieldProtocol,value);
        };

        short_word  GetPackeType() const {
            return GetFieldValue<short_word>(FieldPackeType);
        };

        short_word  GetAddressType() const {
            return GetFieldValue<short_word>(FieldAddressType);
        };

        short_word  GetAddressLength() const {
            return GetFieldValue<short_word>(FieldAddressLength);
        };

        std::string  GetSourceAddress() const {
            return GetFieldValue<std::string>(FieldSourceAddress);
        };

        std::vector<byte>   GetPad() const {
            return GetFieldValue<std::vector<byte> >(FieldPad);
        };

        short_word  GetProtocol() const {
            return GetFieldValue<short_word>(FieldProtocol);
        };

        ~SLL() { /* Destructor */ };

    };

}

#endif /* SLL_H_ */
