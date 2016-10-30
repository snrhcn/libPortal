#include "IPv6RoutingHeader.h"

using namespace Portal;
using namespace std;

IPv6RoutingHeader::IPv6RoutingHeader(const size_t &hdr_size,
        const char *layer_name, const word &proto_id, const bool &reset_fields) {

    allocate_bytes(hdr_size);
    SetName(layer_name);
    SetprotoID(proto_id);
    DefineProtocol();

    SetDefaultValues();

    if (reset_fields)
        ResetFields();
}

void IPv6RoutingHeader::DefineProtocol() {
    Fields.push_back(new ByteField("NextHeader",0,0));
    Fields.push_back(new ByteField("HeaderExtLen",0,1));
    Fields.push_back(new ByteField("RoutingType",0,2));
    Fields.push_back(new ByteField("SegmentLeft",0,3));
}

void IPv6RoutingHeader::SetDefaultValues() {
    SetNextHeader(0);
    SetHeaderExtLen(0);
    SetRoutingType(0);
    SetSegmentLeft(0);
}
