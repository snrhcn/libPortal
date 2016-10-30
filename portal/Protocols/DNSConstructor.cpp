#include "DNS.h"

using namespace Portal;
using namespace std;

DNS::DNS() {

    allocate_bytes(12);
    SetName("DNS");
    SetprotoID(0xfff3);
    DefineProtocol();

    SetIdentification(0);
    SetQRFlag(0);
    SetOpCode(0);
    SetAAFlag(0);
    SetTCFlag(0);
    SetRDFlag(0);
    SetRAFlag(0);
    SetZFlag(0);
    SetADFlag(0);
    SetCDFlag(0);
    SetRCode(0);
    SetTotalQuestions(0);
    SetTotalAnswer(0);
    SetTotalAuthority(0);
    SetTotalAdditional(0);

    ResetFields();

}

void DNS::DefineProtocol() {
    Fields.push_back(new XShortField("Identification",0,0));
    Fields.push_back(new BitFlag<16>("QRFlag",0,"Response","Query"));
    Fields.push_back(new BitsField<4,17>("OpCode",0));
    Fields.push_back(new BitsField<1,21>("AAFlag",0));
    Fields.push_back(new BitsField<1,22>("TCFlag",0));
    Fields.push_back(new BitsField<1,23>("RDFlag",0));
    Fields.push_back(new BitsField<1,24>("RAFlag",0));
    Fields.push_back(new BitsField<1,25>("ZFlag",0));
    Fields.push_back(new BitsField<1,26>("ADFlag",0));
    Fields.push_back(new BitsField<1,27>("CDFlag",0));
    Fields.push_back(new BitsField<4,28>("RCode",0));
    Fields.push_back(new ShortField("TotalQuestions",1,0));
    Fields.push_back(new ShortField("TotalAnswer",1,2));
    Fields.push_back(new ShortField("TotalAuthority",2,0));
    Fields.push_back(new ShortField("TotalAdditional",2,2));
}
