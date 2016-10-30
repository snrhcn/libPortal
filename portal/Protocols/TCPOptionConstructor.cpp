#include "TCPOption.h"

using namespace Portal;
using namespace std;

static TCPOptionPad SetOptionKind(byte value) {
	TCPOptionPad pad;
	pad.SetKind(value);
	return pad;
}

const TCPOptionPad TCPOption::NOP = SetOptionKind(0x01);
const TCPOptionPad TCPOption::EOL = SetOptionKind(0x00);

TCPOption::TCPOption() {

    allocate_bytes(2);
    SetName("TCPOption");
    SetprotoID(0x9000);
    DefineProtocol();

    SetKind(0);
    SetLength(2);

    ResetFields();
}

void TCPOption::DefineProtocol() {
    Fields.push_back(new ByteField("Kind",0,0));
    Fields.push_back(new ByteField("Length",0,1));
}

TCPOptionSACKPermitted::TCPOptionSACKPermitted() {

    SetName("TCPOptionSACKPermitted");
    SetprotoID(0x9004);

    SetKind(0x04);
    SetLength(2);

    ResetFields();
}

TCPOptionSACK::TCPOptionSACK() {

    SetName("TCPOptionSACK");
    SetprotoID(0x9005);

    SetKind(0x05);
    SetLength(2);

    ResetFields();
}

TCPOptionFastOpen::TCPOptionFastOpen() {

    SetName("TCPOptionFastOpen");
    SetprotoID(TCPOptionFastOpen::PROTO);

    SetKind(TCPOPT_TFO);
    SetLength(2);

    ResetFields();
}

TCPOptionEDO::TCPOptionEDO(byte length) : TCPOption() {
	SetName("TCPOptionEDO");
    SetprotoID(TCPOptionEDO::PROTO);

    SetKind(TCPOPT_EDO);
    SetLength(length);

    ResetFields();
}
