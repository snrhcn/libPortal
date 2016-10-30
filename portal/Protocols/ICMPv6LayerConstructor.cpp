#include "ICMPv6Layer.h"

using namespace Portal;
using namespace std;

ICMPv6Layer::ICMPv6Layer() {
	DefineProtocol();
}

void ICMPv6Layer::DefineProtocol() {
    Fields.push_back(new ByteField("Type",0,0));
    Fields.push_back(new ByteField("Code",0,1));
    Fields.push_back(new XShortField("CheckSum",0,2));
}

