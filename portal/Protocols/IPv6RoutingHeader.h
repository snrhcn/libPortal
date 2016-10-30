#ifndef IPv6RoutingHeader_H_
#define IPv6RoutingHeader_H_

#include "../Layer.h"

namespace Portal {

    class IPv6RoutingHeader: public Layer {

        Constructor GetConstructor() const {
            return IPv6RoutingHeader::IPv6RoutingHeaderConstFunc;
        };

        static Layer* IPv6RoutingHeaderConstFunc() {
            return new IPv6RoutingHeader;
        };

        void DefineProtocol();

        void SetDefaultValues();

    protected:
        virtual void Portal();

        virtual void ParseLayerData(ParseInfo* info);

        /* Return the size of the payload carried by this routing header */
        virtual size_t GetRoutingPayloadSize() const;

        /* Copy the raw data of the payload of this routing header */
        virtual void FillRoutingPayload(byte *payload) const;

        static const byte FieldNextHeader = 0;
        static const byte FieldHeaderExtLen = 1;
        static const byte FieldRoutingType = 2;
        static const byte FieldSegmentLeft = 3;

    public:

		enum { PROTO = 0x2b00 };

        IPv6RoutingHeader(const size_t &hdr_size=4,
                               const char *layer_name="IPv6RoutingHeader",
                               const word &proto_id=0x2b00,
                               const bool &reset_fields=true);

        IPv6RoutingHeader(const IPv6RoutingHeader &other)
            : Layer(other) {}

        IPv6RoutingHeader& operator=(const IPv6RoutingHeader &right) {
            Layer::operator=(right);
            return *this;
        }

        Layer& operator=(const Layer &right) {
            if (GetName() != right.GetName())
				throw std::runtime_error("Cannot convert " + right.GetName() + " to " + GetName());
			return IPv6RoutingHeader::operator=(dynamic_cast<const IPv6RoutingHeader&>(right));
        }

        void SetNextHeader(const byte& value) {
            SetFieldValue(FieldNextHeader,value);
        };

        void SetHeaderExtLen(const byte& value) {
            SetFieldValue(FieldHeaderExtLen,value);
        };

        void SetRoutingType(const byte& value) {
            SetFieldValue(FieldRoutingType,value);
        };

        void SetSegmentLeft(const byte& value) {
            SetFieldValue(FieldSegmentLeft,value);
        };

        byte  GetNextHeader() const {
            return GetFieldValue<byte>(FieldNextHeader);
        };

        byte  GetHeaderExtLen() const {
            return GetFieldValue<byte>(FieldHeaderExtLen);
        };

        byte  GetRoutingType() const {
            return GetFieldValue<byte>(FieldRoutingType);
        };

        byte  GetSegmentLeft() const {
            return GetFieldValue<byte>(FieldSegmentLeft);
        };

        /* Build IPv6RoutingHeader layer from type */
        static IPv6RoutingHeader* Build(int type);

        ~IPv6RoutingHeader() { /* Destructor */ };

    };

}

#endif /* IPv6RoutingHeader_H_ */
