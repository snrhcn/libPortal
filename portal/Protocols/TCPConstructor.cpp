#include "TCP.h"

using namespace Portal;
using namespace std;

TCP::TCP() {

    allocate_bytes(20);
    SetName("TCP");
    SetprotoID(0x06);
    DefineProtocol();

    SetSrcPort(0);
    SetDstPort(80);
    SetSeqNumber(0);
    SetAckNumber(0);
    SetDataOffset(5);
    SetReserved(0);
    SetFlags(0);
    SetWindowsSize(5840);
    SetCheckSum(0);
    SetUrgPointer(0);

    ResetFields();

}

void TCP::DefineProtocol() {
    Fields.push_back(new ShortField("SrcPort",0,0));
    Fields.push_back(new ShortField("DstPort",0,2));
    Fields.push_back(new WordField("SeqNumber",1,0));
    Fields.push_back(new WordField("AckNumber",2,0));
    Fields.push_back(new BitsField<4,0>("DataOffset",3));
    Fields.push_back(new BitsField<4,4>("Reserved",3));
    Fields.push_back(new TCPFlags("Flags",3,1));
    Fields.push_back(new ShortField("WindowsSize",3,2));
    Fields.push_back(new XShortField("CheckSum",4,0));
    Fields.push_back(new ShortField("UrgPointer",4,2));
}

