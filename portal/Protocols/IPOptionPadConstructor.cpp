#include "IPOptionPad.h"

using namespace Portal;
using namespace std;

IPOptionPad::IPOptionPad() {

    allocate_bytes(1);
    SetName("IPOptionPad");
    SetprotoID(0x5001);
    DefineProtocol();

    SetCopyFlag(0);
    SetClass(0);
    SetOption(1);

    ResetFields();

}

void IPOptionPad::DefineProtocol() {
    Fields.push_back(new BitsField<1,0>("CopyFlag",0));
    Fields.push_back(new BitsField<2,1>("Class",0));
    Fields.push_back(new BitsField<5,3>("Option",0));
}

