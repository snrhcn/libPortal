#include "IPv6SegmentRoutingHeader.h"

using namespace Portal;
using namespace std;

IPv6SegmentRoutingHeader::IPv6SegmentRoutingHeader()
    : IPv6RoutingHeader(8, "IPv6SegmentRoutingHeader", 0x2b04, false) {
    DefineProtocol();
    SetDefaultValues();
    ResetFields();
}

void IPv6SegmentRoutingHeader::DefineProtocol() {
    Fields.push_back(new ByteField("FirstSegment",1,0));
    Fields.push_back(new BitFlag<8>("CFlag",1,"Cleanup","Keep"));
    Fields.push_back(new BitFlag<9>("PFlag",1,"Protected","NoFRR"));
    Fields.push_back(new BitsField<2,10>("Reserved",1));
    Fields.push_back(new BitsField<3,12>("PolicyFlag1",1));
    Fields.push_back(new BitsField<3,15>("PolicyFlag2",1));
    Fields.push_back(new BitsField<3,18>("PolicyFlag3",1));
    Fields.push_back(new BitsField<3,21>("PolicyFlag4",1));
    Fields.push_back(new ByteField("HMACKeyID",1,3));
}

void IPv6SegmentRoutingHeader::SetDefaultValues() {
    SetRoutingType(4);
    SetFirstSegment(0);
    SetCFlag(0);
    SetPFlag(0);
    SetReserved(0);
    for (size_t i = 0; i < policy_list_t::GetSize(); ++i)
        SetPolicyFlag(i, 0);
    SetHMACKeyID(0);
}

