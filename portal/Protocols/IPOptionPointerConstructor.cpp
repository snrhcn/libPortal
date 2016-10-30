#include "IPOptionPointer.h"

using namespace Portal;
using namespace std;

void IPOptionPointer::DefineProtocol() {
    Fields.push_back(new BitsField<1,0>("CopyFlag",0));
    Fields.push_back(new BitsField<2,1>("Class",0));
    Fields.push_back(new BitsField<5,3>("Option",0));
    Fields.push_back(new ByteField("Length",0,1));
    Fields.push_back(new ByteField("Pointer",0,2));
}

IPOptionLSRR::IPOptionLSRR() {

    allocate_bytes(3);
    SetName("IPOptionLSRR");
    SetprotoID(0x5003);
    DefineProtocol();

    SetCopyFlag(1);
    SetClass(0);
    SetOption(3);
    SetLength(3);
    SetPointer(4);

    ResetFields();

}

IPOptionRR::IPOptionRR() {

    allocate_bytes(3);
    SetName("IPOptionRR");
    SetprotoID(0x5004);
    DefineProtocol();

    SetCopyFlag(0);
    SetClass(0);
    SetOption(7);
    SetLength(3);
    SetPointer(4);

    ResetFields();

}

IPOptionSSRR::IPOptionSSRR() {

    allocate_bytes(3);
    SetName("IPOptionSSRR");
    SetprotoID(0x5005);
    DefineProtocol();

    SetCopyFlag(1);
    SetClass(0);
    SetOption(9);
    SetLength(3);
    SetPointer(4);

    ResetFields();

}
