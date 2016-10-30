#include "NullLoopback.h"
#include "IP.h"
#include "IPv6.h"
#include "RawLayer.h"

const int BSD_AF_INET = 2;
const int BSD_AF_INET6_BSD = 24;     /* OpenBSD (and probably NetBSD), BSD/OS */
const int BSD_AF_INET6_FREEBSD = 28;
const int BSD_AF_INET6_DARWIN = 30;

using namespace Portal;
using namespace std;

void NullLoopback::Portal() {
	/* Nothing to do */
}

void NullLoopback::ParseLayerData(ParseInfo* info) {
	word network_layer = GetFamily();
	word proto_id;
	/* Get next layer */
    switch (network_layer) {

    case BSD_AF_INET:
    	proto_id = IP::PROTO;
      break;

    case BSD_AF_INET6_BSD:
    case BSD_AF_INET6_FREEBSD:
    case BSD_AF_INET6_DARWIN:
    	proto_id = IPv6::PROTO;
      break;

    default:
    	/* Go figure... */
    	proto_id = RawLayer::PROTO;
      break;
    }
	info->next_layer = Protocol::AccessFactory()->GetLayerByID(proto_id);
}

