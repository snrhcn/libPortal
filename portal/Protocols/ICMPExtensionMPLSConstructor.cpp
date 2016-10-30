#include "ICMPExtensionMPLS.h"

using namespace Portal;
using namespace std;

ICMPExtensionMPLS::ICMPExtensionMPLS() {

    allocate_bytes(4);
    SetName("ICMPExtensionMPLS");
    SetprotoID(0xfd);
    DefineProtocol();

    SetLabel(0);
    SetExperimental(0);
    SetBottomOfStack(0);
    SetTTL(0);

    ResetFields();

}

void ICMPExtensionMPLS::DefineProtocol() {
    Fields.push_back(new BitsField<20,0>("Label",0));
    Fields.push_back(new BitsField<3,20>("Experimental",0));
    Fields.push_back(new BitsField<1,23>("BottomOfStack",0));
    Fields.push_back(new ByteField("TTL",0,3));
}

