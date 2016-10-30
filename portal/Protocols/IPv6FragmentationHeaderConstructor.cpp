#include "IPv6FragmentationHeader.h"

using namespace Portal;
using namespace std;

IPv6FragmentationHeader::IPv6FragmentationHeader() {

    allocate_bytes(8);
    SetName("IPv6FragmentationHeader");
    SetprotoID(0x2c);
    DefineProtocol();

    SetNextHeader(0x06);
    SetReserved(0);
    SetFragmentOffset(0);
    SetRes(0);
    SetMflag(0);
    SetIdentification(0);

    ResetFields();

}

void IPv6FragmentationHeader::DefineProtocol() {
    Fields.push_back(new ByteField("NextHeader",0,0));
    Fields.push_back(new ByteField("Reserved",0,1));
    Fields.push_back(new BitsField<13,16>("FragmentOffset",0));
    Fields.push_back(new BitsField<2,29>("Res",0));
    Fields.push_back(new BitsField<1,31>("Mflag",0));
    Fields.push_back(new XWordField("Identification",1,0));
}

