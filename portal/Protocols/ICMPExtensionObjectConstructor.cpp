#include "ICMPExtensionObject.h"

using namespace Portal;
using namespace std;

ICMPExtensionObject::ICMPExtensionObject() {

    allocate_bytes(4);
    SetName("ICMPExtensionObject");
    SetprotoID(0xfe);
    DefineProtocol();

    SetLength(0);
    SetClassNum(0);
    SetCType(0);

    ResetFields();

}

void ICMPExtensionObject::DefineProtocol() {
    Fields.push_back(new ShortField("Length",0,0));
    Fields.push_back(new ByteField("ClassNum",0,2));
    Fields.push_back(new ByteField("CType",0,3));
}

