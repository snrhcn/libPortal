#include "ICMPExtension.h"

using namespace Portal;
using namespace std;

ICMPExtension::ICMPExtension() {

    allocate_bytes(4);
    SetName("ICMPExtension");
    SetprotoID(0xff);
    DefineProtocol();

    SetVersion(2);
    SetReserved(0);
    SetCheckSum(0);

    ResetFields();

}

void ICMPExtension::DefineProtocol() {
    Fields.push_back(new BitsField<4,0>("Version",0));
    Fields.push_back(new BitsField<12,4>("Reserved",0));
    Fields.push_back(new XShortField("CheckSum",0,2));
}

