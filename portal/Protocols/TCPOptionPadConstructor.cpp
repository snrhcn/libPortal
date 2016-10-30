#include "TCPOptionPad.h"

using namespace Portal;
using namespace std;

TCPOptionPad::TCPOptionPad() {

    allocate_bytes(1);
    SetName("TCPOptionPad");
    SetprotoID(0x9003);
    DefineProtocol();

    /* NOP padding */
    SetKind(0x01);

    ResetFields();

}

void TCPOptionPad::DefineProtocol() {
    Fields.push_back(new ByteField("Kind",0,0));
}

