#include "Ethernet.h"

using namespace Portal;
using namespace std;

Ethernet::Ethernet() {

    allocate_bytes(14);
    SetName("Ethernet");
    SetprotoID(0xfff2);
    DefineProtocol();

    SetDestinationMAC("ff:ff:ff:ff:ff:ff");
    SetSourceMAC("00:00:00:00:00:00");
    SetType(0x0800);

    ResetFields();

}

void Ethernet::DefineProtocol() {
    Fields.push_back(new MACAddress("DestinationMAC",0,0));
    Fields.push_back(new MACAddress("SourceMAC",1,2));
    Fields.push_back(new XShortField("Type",3,0));
}

