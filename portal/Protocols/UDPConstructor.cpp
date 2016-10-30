#include "UDP.h"

using namespace Portal;
using namespace std;

UDP::UDP() {

    allocate_bytes(8);
    SetName("UDP");
    SetprotoID(0x11);
    DefineProtocol();

    SetSrcPort(0);
    SetDstPort(53);
    SetLength(0);
    SetCheckSum(0);

    ResetFields();

}

void UDP::DefineProtocol() {
    Fields.push_back(new ShortField("SrcPort",0,0));
    Fields.push_back(new ShortField("DstPort",0,2));
    Fields.push_back(new ShortField("Length",1,0));
    Fields.push_back(new XShortField("CheckSum",1,2));
}

