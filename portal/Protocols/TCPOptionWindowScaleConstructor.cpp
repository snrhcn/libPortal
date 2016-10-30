#include "TCPOptionWindowScale.h"

using namespace Portal;
using namespace std;

TCPOptionWindowScale::TCPOptionWindowScale() {

	allocate_bytes(3);
    SetName("TCPOptionWindowScale");
    SetprotoID(0x9008);
	DefineProtocol();

    SetKind(0x03);
    SetLength(3);

}

void TCPOptionWindowScale::DefineProtocol() {
    Fields.push_back(new ByteField("Kind",0,0));
    Fields.push_back(new ByteField("Length",0,1));
    Fields.push_back(new ByteField("Shift",0,2));
}
