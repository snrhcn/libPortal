#include "TCPOptionMaxSegSize.h"

using namespace Portal;
using namespace std;

TCPOptionMaxSegSize::TCPOptionMaxSegSize() {

    allocate_bytes(4);
    SetName("TCPOptionMaxSegSize");
    SetprotoID(0x9001);
    DefineProtocol();

    SetKind(2);
    SetLength(4);
    SetMaxSegSize(0);

    ResetFields();

}

void TCPOptionMaxSegSize::DefineProtocol() {
    Fields.push_back(new ByteField("Kind",0,0));
    Fields.push_back(new ByteField("Length",0,1));
    Fields.push_back(new ShortField("MaxSegSize",0,2));
}

