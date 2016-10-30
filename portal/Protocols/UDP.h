#ifndef UDP_H_
#define UDP_H_

#include "../Layer.h"

namespace Portal {

    class UDP: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return UDP::UDPConstFunc;
        };

        static Layer* UDPConstFunc() {
            return new UDP;
        };

        void Portal();

        std::string MatchFilter() const;

        void ReDefineActiveFields();

        static const byte FieldSrcPort = 0;
        static const byte FieldDstPort = 1;
        static const byte FieldLength = 2;
        static const byte FieldCheckSum = 3;

    public:

		enum { PROTO = 0x11 };

        UDP();

        void SetSrcPort(const short_word& value) {
            SetFieldValue(FieldSrcPort,value);
        };

        void SetDstPort(const short_word& value) {
            SetFieldValue(FieldDstPort,value);
        };

        void SetLength(const short_word& value) {
            SetFieldValue(FieldLength,value);
        };

        void SetCheckSum(const short_word& value) {
            SetFieldValue(FieldCheckSum,value);
        };

        short_word  GetSrcPort() const {
            return GetFieldValue<short_word>(FieldSrcPort);
        };

        short_word  GetDstPort() const {
            return GetFieldValue<short_word>(FieldDstPort);
        };

        short_word  GetLength() const {
            return GetFieldValue<short_word>(FieldLength);
        };

        short_word  GetCheckSum() const {
            return GetFieldValue<short_word>(FieldCheckSum);
        };

        ~UDP() { /* Destructor */ };

    };

}

#endif /* UDP_H_ */
