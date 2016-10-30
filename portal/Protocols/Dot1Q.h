#ifndef Dot1Q_H_
#define Dot1Q_H_

#include "../Layer.h"

namespace Portal {

    class Dot1Q: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return Dot1Q::Dot1QConstFunc;
        };

        static Layer* Dot1QConstFunc() {
            return new Dot1Q;
        };

        void Portal();

        void ReDefineActiveFields();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldPCP = 0;
        static const byte FieldDEI = 1;
        static const byte FieldVID = 2;
        static const byte FieldType = 3;

    public:

		enum { PROTO = 0x8100 };

        Dot1Q();

        void SetPCP(const word& value) {
            SetFieldValue(FieldPCP,value);
        };

        void SetDEI(const word& value) {
            SetFieldValue(FieldDEI,value);
        };

        void SetVID(const word& value) {
            SetFieldValue(FieldVID,value);
        };

        void SetType(const short_word& value) {
            SetFieldValue(FieldType,value);
        };

        word  GetPCP() const {
            return GetFieldValue<word>(FieldPCP);
        };

        word  GetDEI() const {
            return GetFieldValue<word>(FieldDEI);
        };

        word  GetVID() const {
            return GetFieldValue<word>(FieldVID);
        };

        short_word  GetType() const {
            return GetFieldValue<short_word>(FieldType);
        };

        ~Dot1Q() { /* Destructor */ };

    };

}

#endif /* Dot1Q_H_ */
