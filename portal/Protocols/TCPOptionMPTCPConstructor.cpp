#include "TCPOptionMPTCP.h"

using namespace Portal;
using namespace std;

TCPOptionMPTCP::TCPOptionMPTCP() {

    allocate_bytes(2);
    SetName("TCPOptionMPTCP");
    SetprotoID(0x9006);
    DefineProtocol();

    SetKind(30);
    SetLength(2);
}

void TCPOptionMPTCP::DefineProtocol() {
    Fields.push_back(new ByteField("Kind",0,0));
    Fields.push_back(new ByteField("Length",0,1));
    Fields.push_back(new BitsField<4,16>("Subtype",0));
}

TCPOptionMPTCPCapable::TCPOptionMPTCPCapable() {
    allocate_bytes(12);
    SetName("TCPOptionMPTCPCapable");
    SetprotoID(0x9007);
    DefineProtocol();

    SetKind(30);
    SetLength(12);
    SetVersion(0);
    SetSubtype(0);
    SetCrypto(1);
}

void TCPOptionMPTCPCapable::DefineProtocol() {
    Fields.push_back(new BitsField<4,20>("Version",0));
    Fields.push_back(new BitFlag<24>("Checksum",0,"Checksum Enabled","Checksum Disabled"));
    Fields.push_back(new BitsField<6,25>("Flags",0));
    Fields.push_back(new BitFlag<31>("Crypto",0,"HMAC-SHA1","NO HMAC-SHA1"));
    Fields.push_back(new Int64Field("Sender's Key",1,0));
}

TCPOptionMPTCPJoin::TCPOptionMPTCPJoin() {
    allocate_bytes(12);
    SetName("TCPOptionMPTCPJoin");
    SetprotoID(0x9009);
    DefineProtocol();

    SetKind(30);
    SetLength(12);
    SetSubtype(1);
    SetBackupPath(0);

}

void TCPOptionMPTCPJoin::DefineProtocol() {
    Fields.push_back(new BitsField<3,20>("Blank",0));
    Fields.push_back(new BitFlag<23>("BackupPath",0,"This is a Backup path","This is not a Backup Path"));
    Fields.push_back(new ByteField("AddrID",0,3));
    Fields.push_back(new WordField("Receiver's Token",1,0));
    Fields.push_back(new WordField("Sender's Random Number",2,0));
}
