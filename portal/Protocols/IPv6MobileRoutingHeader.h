#ifndef IPV6MOBILEROUTINGHEADER_H_
#define IPV6MOBILEROUTINGHEADER_H_

#include "../Layer.h"
#include "IPv6RoutingHeader.h"

namespace Portal {

    class IPv6MobileRoutingHeader: public IPv6RoutingHeader {

        void DefineProtocol();

        void SetDefaultValues();

        Constructor GetConstructor() const {
            return IPv6MobileRoutingHeader::IPv6MobileRoutingHeaderConstFunc;
        };

        static Layer* IPv6MobileRoutingHeaderConstFunc() {
            return new IPv6MobileRoutingHeader;
        };

        void Portal();

        /* Generic routing header has field 0-3 */
        static const byte FieldReserved = 4;
        static const byte FieldHomeAddress = 5;

    protected:

        /* Everything is already included in the header */
        size_t GetRoutingPayloadSize() const { return 0; }
        /* Nothing to do here */
        void FillRoutingPayload(byte *payload) const { (void)payload; }

    public:

        enum { PROTO = 0x2b02 };

        IPv6MobileRoutingHeader();

        IPv6MobileRoutingHeader(const IPv6MobileRoutingHeader& mrh)
            : IPv6RoutingHeader(mrh) { };

		/* Assignment operator of this class */
		IPv6MobileRoutingHeader& operator=(const IPv6MobileRoutingHeader& right) {
			IPv6RoutingHeader::operator=(right);
            return *this;
		}

		Layer& operator=(const Layer& right) {
			if (GetName() != right.GetName())
				throw std::runtime_error("Cannot convert "
                        + right.GetName() + " to " + GetName());
			return IPv6MobileRoutingHeader::operator=(
                    dynamic_cast<const IPv6MobileRoutingHeader&>(right));
		}

        void SetReserved(const word& value) {
            SetFieldValue(FieldReserved,value);
        };

        void SetHomeAddress(const std::string& value) {
            SetFieldValue(FieldHomeAddress,value);
        };

        word  GetReserved() const {
            return GetFieldValue<word>(FieldReserved);
        };

        std::string  GetHomeAddress() const {
            return GetFieldValue<std::string>(FieldHomeAddress);
        };

        ~IPv6MobileRoutingHeader() { /* Destructor */ };

    };

}

#endif /* IPV6MOBILEROUTINGHEADER_H_ */
