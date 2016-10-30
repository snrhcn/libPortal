#ifndef ICMPEXTENSION_H_
#define ICMPEXTENSION_H_

#include "../Layer.h"

namespace Portal {

    class ICMPExtension: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return ICMPExtension::ICMPExtensionConstFunc;
        };

        static Layer* ICMPExtensionConstFunc() {
            return new ICMPExtension;
        };

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldVersion = 0;
        static const byte FieldReserved = 1;
        static const byte FieldCheckSum = 2;

    public:

		enum { PROTO = 0xff };

        ICMPExtension();

        void SetVersion(const word& value) {
            SetFieldValue(FieldVersion,value);
        };

        void SetReserved(const word& value) {
            SetFieldValue(FieldReserved,value);
        };

        void SetCheckSum(const short_word& value) {
            SetFieldValue(FieldCheckSum,value);
        };

        word  GetVersion() const {
            return GetFieldValue<word>(FieldVersion);
        };

        word  GetReserved() const {
            return GetFieldValue<word>(FieldReserved);
        };

        short_word  GetCheckSum() const {
            return GetFieldValue<short_word>(FieldCheckSum);
        };

        ~ICMPExtension() { /* Destructor */ };

    };

}

#endif /* ICMPEXTENSION_H_ */
