#include "IPv6FragmentationHeader.h"
#include "ICMPv6Layer.h"

using namespace Portal;
using namespace std;

void IPv6FragmentationHeader::ReDefineActiveFields() {}

void IPv6FragmentationHeader::Portal() {}

void IPv6FragmentationHeader::ParseLayerData(ParseInfo* info) {
	short_word network_layer = GetNextHeader();

	if(this->GetFragmentOffset() > 0) {
		info->next_layer = 0;
		return;
	}

	if(network_layer == (ICMPv6Layer::PROTO >> 8)) {
		/* Get ICMPv6 type */
		short_word icmpv6_layer = (info->raw_data + info->offset)[0];
		/* Construct next layer */
		info->next_layer = ICMPv6Layer::Build(icmpv6_layer);
	} else {
		info->next_layer = Protocol::AccessFactory()->GetLayerByID(network_layer);
	}
}

