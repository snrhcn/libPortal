#include "IPv6.h"

using namespace Portal;
using namespace std;

IPv6::IPv6() {

    allocate_bytes(40);
    SetName("IPv6");
    SetprotoID(0x86dd);
    DefineProtocol();

    SetVersion(6);
    SetTrafficClass(0);
    SetFlowLabel(0);
    SetPayloadLength(0);
    SetNextHeader(0x06);
    SetHopLimit(64);
    SetSourceIP("0000::0000");
    SetDestinationIP("0000::0000");

    ResetFields();

}

void IPv6::DefineProtocol() {
    Fields.push_back(new BitsField<4,0>("Version",0));
    Fields.push_back(new BitsField<8,4>("TrafficClass",0));
    Fields.push_back(new BitsField<20,12>("FlowLabel",0));
    Fields.push_back(new ShortField("PayloadLength",1,0));
    Fields.push_back(new ByteField("NextHeader",1,2));
    Fields.push_back(new ByteField("HopLimit",1,3));
    Fields.push_back(new IPv6Address("SourceIP",2,0));
    Fields.push_back(new IPv6Address("DestinationIP",6,0));
}

