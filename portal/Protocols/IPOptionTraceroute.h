#ifndef IPOPTIONTRACEROUTE_H_
#define IPOPTIONTRACEROUTE_H_

#include "IPOptionLayer.h"

namespace Portal {

    class IPOptionTraceroute: public IPOptionLayer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return IPOptionTraceroute::IPOptionTracerouteConstFunc;
        };

        static Layer* IPOptionTracerouteConstFunc() {
            return new IPOptionTraceroute;
        };

        void Portal();

        void ReDefineActiveFields();

        static const byte FieldCopyFlag = 0;
        static const byte FieldClass = 1;
        static const byte FieldOption = 2;
        static const byte FieldLength = 3;
        static const byte FieldIDNumber = 4;
        static const byte FieldOutboundHC = 5;
        static const byte FieldReturnHC = 6;
        static const byte FieldOrigIP = 7;

    public:

        enum { PROTO = 0x5002 };

        IPOptionTraceroute();

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

        void SetIDNumber(const short_word& value) {
            SetFieldValue(FieldIDNumber,value);
        };

        void SetOutboundHC(const short_word& value) {
            SetFieldValue(FieldOutboundHC,value);
        };

        void SetReturnHC(const short_word& value) {
            SetFieldValue(FieldReturnHC,value);
        };

        void SetOrigIP(const std::string& value) {
            SetFieldValue(FieldOrigIP,value);
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

        short_word  GetIDNumber() const {
            return GetFieldValue<short_word>(FieldIDNumber);
        };

        short_word  GetOutboundHC() const {
            return GetFieldValue<short_word>(FieldOutboundHC);
        };

        short_word  GetReturnHC() const {
            return GetFieldValue<short_word>(FieldReturnHC);
        };

        std::string  GetOrigIP() const {
            return GetFieldValue<std::string>(FieldOrigIP);
        };

        ~IPOptionTraceroute() { /* Destructor */ };

    };

}

#endif /* IPOPTIONTRACEROUTE_H_ */
