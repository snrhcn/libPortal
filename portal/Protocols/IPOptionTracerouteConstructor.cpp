#include "IPOptionTraceroute.h"

using namespace Portal;
using namespace std;

IPOptionTraceroute::IPOptionTraceroute() {

    allocate_bytes(12);
    SetName("IPOptionTraceroute");
    SetprotoID(0x5002);
    DefineProtocol();

    SetCopyFlag(0);
    SetClass(2);
    SetOption(18);
    SetLength(12);
    SetIDNumber(0);
    SetOutboundHC(0);
    SetReturnHC(0xffff);
    SetOrigIP("0.0.0.0");

    ResetFields();

}

void IPOptionTraceroute::DefineProtocol() {
    Fields.push_back(new BitsField<1,0>("CopyFlag",0));
    Fields.push_back(new BitsField<2,1>("Class",0));
    Fields.push_back(new BitsField<5,3>("Option",0));
    Fields.push_back(new ByteField("Length",0,1));
    Fields.push_back(new XShortField("IDNumber",0,2));
    Fields.push_back(new ShortField("OutboundHC",1,0));
    Fields.push_back(new XShortField("ReturnHC",1,2));
    Fields.push_back(new IPAddress("OrigIP",2,0));
}

