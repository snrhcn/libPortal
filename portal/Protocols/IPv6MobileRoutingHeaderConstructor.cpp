#include "IPv6MobileRoutingHeader.h"

using namespace Portal;
using namespace std;

IPv6MobileRoutingHeader::IPv6MobileRoutingHeader() 
    : IPv6RoutingHeader(24, "IPv6MobileRoutingHeader", 0x2b02, false) {
    DefineProtocol();
    SetDefaultValues();
    ResetFields();
}

void IPv6MobileRoutingHeader::DefineProtocol() {
    Fields.push_back(new WordField("Reserved",1,0));
    Fields.push_back(new IPv6Address("HomeAddress",2,0));
}

void IPv6MobileRoutingHeader::SetDefaultValues() {
    SetReserved(0);
    SetHomeAddress("::1");
}
