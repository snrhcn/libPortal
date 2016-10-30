#include "SLL.h"

using namespace Portal;
using namespace std;

SLL::SLL() {

    allocate_bytes(16);
    SetName("SLL");
    SetprotoID(0xfff0);
    DefineProtocol();

    SetPackeType(0);
    SetAddressType(1);
    SetAddressLength(6);
    SetSourceAddress("00:00:00:00:00:00");
    SetProtocol(0x0800);

    ResetFields();

}

void SLL::DefineProtocol() {
    Fields.push_back(new ShortField("PackeType",0,0));
    Fields.push_back(new ShortField("AddressType",0,2));
    Fields.push_back(new ShortField("AddressLength",1,0));
    Fields.push_back(new MACAddress("SourceAddress",1,2));
    Fields.push_back(new BytesField<2>("Pad",3,0));
    Fields.push_back(new XShortField("Protocol",3,2));
}

