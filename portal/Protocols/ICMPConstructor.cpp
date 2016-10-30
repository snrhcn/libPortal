#include "ICMP.h"

using namespace Portal;
using namespace std;

ICMP::ICMP() {

    allocate_bytes(8);
    SetName("ICMP");
    SetprotoID(0x01);
    DefineProtocol();

    Fields.SetOverlap(1);

    SetType(8);
    SetCode(0);
    SetCheckSum(0);
    SetRestOfHeader(0);

    ResetFields();

}

void ICMP::DefineProtocol() {
    Fields.push_back(new ByteField("Type",0,0));
    Fields.push_back(new ByteField("Code",0,1));
    Fields.push_back(new XShortField("CheckSum",0,2));
    Fields.push_back(new WordField("RestOfHeader",1,0));
    Fields.push_back(new XShortField("Identifier",1,0));
    Fields.push_back(new XShortField("SequenceNumber",1,2));
    Fields.push_back(new ByteField("Pointer",1,0));
    Fields.push_back(new IPAddress("Gateway",1,0));
    Fields.push_back(new ByteField("Length",1,1));
    Fields.push_back(new ShortField("MTUNextHOP",1,2));
}

