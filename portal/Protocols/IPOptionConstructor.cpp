#include "IPOption.h"

using namespace Portal;
using namespace std;

static IPOptionPad SetOptionValue(byte value) {
	IPOptionPad pad;
	pad.SetOption(value);
	return pad;
}

const IPOptionPad IPOption::NOP = SetOptionValue(0x01);
const IPOptionPad IPOption::EOL = SetOptionValue(0x00);

IPOption::IPOption() {

    allocate_bytes(2);
    SetName("IPOption");
    SetprotoID(0x5000);
    DefineProtocol();

    SetCopyFlag(1);
    SetClass(0);
    SetOption(0);
    SetLength(0);

    ResetFields();

}

void IPOption::DefineProtocol() {
    Fields.push_back(new BitsField<1,0>("CopyFlag",0));
    Fields.push_back(new BitsField<2,1>("Class",0));
    Fields.push_back(new BitsField<5,3>("Option",0));
    Fields.push_back(new ByteField("Length",0,1));
}

