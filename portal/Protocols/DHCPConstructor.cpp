#include "DHCP.h"

using namespace Portal;
using namespace std;

/* Some constant of the DHCP protocol */
const byte DHCP::Request = 0x1;
const byte DHCP::Reply = 0x2;

DHCP::DHCP() {

	allocate_bytes(240);
    SetName("DHCP");
    SetprotoID(0xfff4);
    DefineProtocol();

    SetOperationCode(0x00);
    SetHardwareType(0x01);
    SetHardwareLength(6);
    SetHopCount(0);
    SetTransactionID(0x00);
    SetNumberOfSeconds(0);
    SetFlags(0x8000);
    SetClientIP("0.0.0.0");
    SetYourIP("0.0.0.0");
    SetServerIP("0.0.0.0");
    SetGatewayIP("0.0.0.0");
    SetClientMAC("ff:ff:ff:ff:ff:ff");
    SetServerHostName("");
    SetBootFile("");

    ResetFields();

}

void DHCP::DefineProtocol() {
    Fields.push_back(new XByteField("OperationCode",0,0));
    Fields.push_back(new XByteField("HardwareType",0,1));
    Fields.push_back(new ByteField("HardwareLength",0,2));
    Fields.push_back(new ByteField("HopCount",0,3));
    Fields.push_back(new XWordField("TransactionID",1,0));
    Fields.push_back(new ShortField("NumberOfSeconds",2,0));
    Fields.push_back(new XShortField("Flags",2,2));
    Fields.push_back(new IPAddress("ClientIP",3,0));
    Fields.push_back(new IPAddress("YourIP",4,0));
    Fields.push_back(new IPAddress("ServerIP",5,0));
    Fields.push_back(new IPAddress("GatewayIP",6,0));
    Fields.push_back(new MACAddress("ClientMAC",7,0));
    Fields.push_back(new BytesField<10>("ZeroPadding",8,2));
    Fields.push_back(new StringField<64>("ServerHostName",11,0));
    Fields.push_back(new StringField<128>("BootFile",27,0));
}

