#include "ICMPv6.h"

using namespace Portal;
using namespace std;

ICMPv6::ICMPv6() {

    allocate_bytes(8);
    SetName("ICMPv6");
    SetprotoID(0x3A01);
    DefineProtocol();

    Fields.SetOverlap(1);

    SetType(8);
    SetCode(0);
    SetCheckSum(0);
    SetRestOfHeader(0);
    SetLength(0);

    ResetFields();
}

void ICMPv6::DefineProtocol() {
    Fields.push_back(new WordField("RestOfHeader",1,0));
    Fields.push_back(new WordField("MTU",1,0));
    Fields.push_back(new WordField("Pointer",1,0));
    Fields.push_back(new XShortField("Identifier",1,0));
    Fields.push_back(new XShortField("SequenceNumber",1,2));
    Fields.push_back(new ByteField("Length",1,0));
}

