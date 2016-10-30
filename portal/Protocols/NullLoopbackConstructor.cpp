#include "NullLoopback.h"

using namespace Portal;
using namespace std;

NullLoopback::NullLoopback() {

    allocate_bytes(4);
    SetName("NullLoopback");
    SetprotoID(0xfff5);
    DefineProtocol();

    SetFamily(0);

    ResetFields();

}

void NullLoopback::DefineProtocol() {
    Fields.push_back(new WordHostField("Family",0,0));
}

