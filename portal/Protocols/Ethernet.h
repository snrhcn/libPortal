#ifndef ETHERNET_H_
#define ETHERNET_H_

#include "../Layer.h"

namespace Portal {

    class Ethernet: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return Ethernet::EthernetConstFunc;
        };

        static Layer* EthernetConstFunc() {
            return new Ethernet;
        };

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldDestinationMAC = 0;
        static const byte FieldSourceMAC = 1;
        static const byte FieldType = 2;

    public:

		enum { PROTO = 0xfff2 };

        Ethernet();

        void SetDestinationMAC(const std::string& value) {
            SetFieldValue(FieldDestinationMAC,value);
        };

        void SetSourceMAC(const std::string& value) {
            SetFieldValue(FieldSourceMAC,value);
        };

        void SetType(const short_word& value) {
            SetFieldValue(FieldType,value);
        };

        std::string  GetDestinationMAC() const {
            return GetFieldValue<std::string>(FieldDestinationMAC);
        };

        std::string  GetSourceMAC() const {
            return GetFieldValue<std::string>(FieldSourceMAC);
        };

        short_word  GetType() const {
            return GetFieldValue<short_word>(FieldType);
        };

        ~Ethernet() { /* Destructor */ };

    };

}

#endif /* ETHERNET_H_ */
