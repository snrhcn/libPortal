#ifndef NULLLOOPBACK_H_
#define NULLLOOPBACK_H_

#include "../Layer.h"

namespace Portal {

    class NullLoopback: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return NullLoopback::NullLoopbackConstFunc;
        };

        static Layer* NullLoopbackConstFunc() {
            return new NullLoopback;
        };

        void Portal();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldFamily = 0;

    public:

        enum { PROTO = 0xfff5 };

        NullLoopback();

        void SetFamily(const word& value) {
            SetFieldValue(FieldFamily,value);
        };

        word  GetFamily() const {
            return GetFieldValue<word>(FieldFamily);
        };

        ~NullLoopback() { /* Destructor */ };

    };

}

#endif /* NULLLOOPBACK_H_ */
