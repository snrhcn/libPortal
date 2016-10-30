#include "ARP.h"

using namespace Portal;
using namespace std;

ARP::ARP() {

    allocate_bytes(28);
    SetName("ARP");
    SetprotoID(0x0806);
    DefineProtocol();

    SetHardwareType(0x01);
    SetProtocolType(0x0800);
    SetHardwareLength(0x06);
    SetProtocolLength(0x04);
    SetOperation(0x01);
    SetSenderMAC("00:00:00:00:00:00");
    SetSenderIP("127.0.0.1");
    SetTargetMAC("00:00:00:00:00:00");
    SetTargetIP("127.0.0.1");

    ResetFields();

}

void ARP::DefineProtocol() {
    Fields.push_back(new XShortField("HardwareType",0,0));
    Fields.push_back(new XShortField("ProtocolType",0,2));
    Fields.push_back(new ByteField("HardwareLength",1,0));
    Fields.push_back(new ByteField("ProtocolLength",1,1));
    Fields.push_back(new ShortField("Operation",1,2));
    Fields.push_back(new MACAddress("SenderMAC",2,0));
    Fields.push_back(new IPAddress("SenderIP",3,2));
    Fields.push_back(new MACAddress("TargetMAC",4,2));
    Fields.push_back(new IPAddress("TargetIP",6,0));
}

