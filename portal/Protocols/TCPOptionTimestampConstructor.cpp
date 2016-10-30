#include "TCPOptionTimestamp.h"

using namespace Portal;
using namespace std;

TCPOptionTimestamp::TCPOptionTimestamp() {

    allocate_bytes(10);
    SetName("TCPOptionTimestamp");
    SetprotoID(0x9002);
    DefineProtocol();

    SetKind(8);
    SetLength(10);
    SetValue(0);
    SetEchoReply(0);

    ResetFields();

}

void TCPOptionTimestamp::DefineProtocol() {
    Fields.push_back(new ByteField("Kind",0,0));
    Fields.push_back(new ByteField("Length",0,1));
    Fields.push_back(new WordField("Value",0,2));
    Fields.push_back(new WordField("EchoReply",1,2));
}

