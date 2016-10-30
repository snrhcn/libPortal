#include "IP.h"

using namespace Portal;
using namespace std;

IP::IP() {

    allocate_bytes(20);
    SetName("IP");
    SetprotoID(0x0800);
    DefineProtocol();

    SetVersion(4);
    SetHeaderLength(5);
    SetDiffServicesCP(0);
    SetExpCongestionNot(0);
    SetTotalLength(0);
    SetIdentification(0);
#ifdef __APPLE__
    SetFlags(0);
#else
    SetFlags(0x02);
#endif
    SetFragmentOffset(0);
    SetTTL(64);
    SetProtocol(0x06);
    SetCheckSum(0);
    SetSourceIP("0.0.0.0");
    SetDestinationIP("0.0.0.0");

    ResetFields();

}

void IP::DefineProtocol() {
    Fields.push_back(new BitsField<4,0>("Version",0));
    Fields.push_back(new BitsField<4,4>("HeaderLength",0));
    Fields.push_back(new BitsField<6,8>("DiffServicesCP",0));
    Fields.push_back(new BitsField<2,14>("ExpCongestionNot",0));
#ifdef __APPLE__
	/* see http://cseweb.ucsd.edu/~braghava/notes/freebsd-sockets.txt */
    Fields.push_back(new ShortHostNetField("TotalLength",0,2));
#else
    Fields.push_back(new ShortField("TotalLength",0,2));
#endif
    Fields.push_back(new XShortField("Identification",1,0));
    Fields.push_back(new BitsField<3,16>("Flags",1));
    Fields.push_back(new BitsField<13,19>("FragmentOffset",1));
    Fields.push_back(new ByteField("TTL",2,0));
    Fields.push_back(new XByteField("Protocol",2,1));
    Fields.push_back(new XShortField("CheckSum",2,2));
    Fields.push_back(new IPAddress("SourceIP",3,0));
    Fields.push_back(new IPAddress("DestinationIP",4,0));
}

