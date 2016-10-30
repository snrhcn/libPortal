#ifndef ICMPEXTENSIONOBJECT_H_
#define ICMPEXTENSIONOBJECT_H_

#include "../Layer.h"

namespace Portal {

    class ICMPExtensionObject: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return ICMPExtensionObject::ICMPExtensionObjectConstFunc;
        };

        static Layer* ICMPExtensionObjectConstFunc() {
            return new ICMPExtensionObject;
        };

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldLength = 0;
        static const byte FieldClassNum = 1;
        static const byte FieldCType = 2;

    public:

		enum { PROTO = 0xfe };

        /* Classes (ClassNum) */
        static const byte MPLS;

        /* Types (CType) */
        /* +++ MPLS +++ */
        static const byte MPLSReserved;
        static const byte MPLSIncoming;

        ICMPExtensionObject();

        void SetLength(const short_word& value) {
            SetFieldValue(FieldLength,value);
        };

        void SetClassNum(const byte& value) {
            SetFieldValue(FieldClassNum,value);
        };

        void SetCType(const byte& value) {
            SetFieldValue(FieldCType,value);
        };

        short_word  GetLength() const {
            return GetFieldValue<short_word>(FieldLength);
        };

        byte  GetClassNum() const {
            return GetFieldValue<byte>(FieldClassNum);
        };

        byte  GetCType() const {
            return GetFieldValue<byte>(FieldCType);
        };

        std::string GetClassName() const;

        ~ICMPExtensionObject() { /* Destructor */ };

    };

}

#endif /* ICMPEXTENSIONOBJECT_H_ */
