#include "Dot1Q.h"

using namespace Portal;
using namespace std;

Dot1Q::Dot1Q() {

    allocate_bytes(4);
    SetName("Dot1Q");
    SetprotoID(0x8100);
    DefineProtocol();

	SetPCP(0);
	SetDEI(0);
	SetVID(0);
    SetType(0x0800);

    ResetFields();

}

void Dot1Q::DefineProtocol() {
    Fields.push_back(new BitsField<3,0>("PCP",0));
    Fields.push_back(new BitsField<1,3>("DEI",0));
    Fields.push_back(new BitsField<12,4>("VID",0));
    Fields.push_back(new XShortField("Type",0,2));
}

