#ifndef ICMPEXTENSIONMPLS_H_
#define ICMPEXTENSIONMPLS_H_

#include "../Layer.h"

namespace Portal {

    class ICMPExtensionMPLS: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return ICMPExtensionMPLS::ICMPExtensionMPLSConstFunc;
        };

        static Layer* ICMPExtensionMPLSConstFunc() {
            return new ICMPExtensionMPLS;
        };

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldLabel = 0;
        static const byte FieldExperimental = 1;
        static const byte FieldBottomOfStack = 2;
        static const byte FieldTTL = 3;

    public:

		enum { PROTO = 0xfd };

        ICMPExtensionMPLS();

        void SetLabel(const word& value) {
            SetFieldValue(FieldLabel,value);
        };

        void SetExperimental(const word& value) {
            SetFieldValue(FieldExperimental,value);
        };

        void SetBottomOfStack(const word& value) {
            SetFieldValue(FieldBottomOfStack,value);
        };

        void SetTTL(const byte& value) {
            SetFieldValue(FieldTTL,value);
        };

        word  GetLabel() const {
            return GetFieldValue<word>(FieldLabel);
        };

        word  GetExperimental() const {
            return GetFieldValue<word>(FieldExperimental);
        };

        word  GetBottomOfStack() const {
            return GetFieldValue<word>(FieldBottomOfStack);
        };

        byte  GetTTL() const {
            return GetFieldValue<byte>(FieldTTL);
        };

        ~ICMPExtensionMPLS() { /* Destructor */ };

    };

}

#endif /* ICMPEXTENSIONMPLS_H_ */
