#ifndef ICMPV6LAYER_H_
#define ICMPV6LAYER_H_

#include "../Layer.h"
#include "ICMPLayer.h"

namespace Portal {

    class ICMPv6Layer: public ICMPLayer {

    protected:

        void DefineProtocol();

        void Portal();

        static const byte FieldType = 0;
        static const byte FieldCode = 1;
        static const byte FieldCheckSum = 2;

    public:

        enum { PROTO = 0x3A00 };

        ICMPv6Layer();

        void SetType(const byte& value) {
            SetFieldValue(FieldType,value);
        };

        void SetCode(const byte& value) {
            SetFieldValue(FieldCode,value);
        };

        void SetCheckSum(const short_word& value) {
            SetFieldValue(FieldCheckSum,value);
        };

        byte  GetType() const {
            return GetFieldValue<byte>(FieldType);
        };

        byte  GetCode() const {
            return GetFieldValue<byte>(FieldCode);
        };

        short_word  GetCheckSum() const {
            return GetFieldValue<short_word>(FieldCheckSum);
        };

        /* Build ICMPv6 layer from type */
        static ICMPv6Layer* Build(int type);

        ~ICMPv6Layer() { /* Destructor */ };

    };

}

#endif /* ICMPV6LAYER_H_ */
