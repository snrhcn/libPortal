#include "ICMPv6Layer.h"
#include "ICMPv6.h"
#include "IPv6.h"

using namespace Portal;
using namespace std;

ICMPv6Layer* ICMPv6Layer::Build(int type) {

	switch(type) {

	case 1 :
	case 2 :
	case 3 :
	case 4 :
	case 128 :
	case 129 :
		return new ICMPv6;
		break;
	}

	/* Generic ICMPv6 Header */
	return new ICMPv6;

}

void ICMPv6Layer::Portal() {
	/* Bottom layer name */
	short_word bottom_layer = 0;

	/* Checksum of UDP packet */
	short_word checksum;

	/* Get total size */
	size_t tot_length = GetRemainingSize();

	/* Bottom layer name (look for IPs layers) */
	Layer* bottom_ptr = GetBottomLayer();

	while(bottom_ptr && (bottom_ptr->GetID() != IPv6::PROTO))
        bottom_ptr = bottom_ptr->GetBottomLayer();

	if(bottom_ptr) bottom_layer = bottom_ptr->GetID();

	if (!IsFieldSet(FieldCheckSum)) {

		/* Set the checksum to zero */
		SetCheckSum(0x0);

		if(bottom_layer == IPv6::PROTO) {
			/* It's OK */
			IPv6* ip_layer = dynamic_cast<IPv6*>(bottom_ptr);

			size_t data_length = 40 + tot_length;

			if(data_length%2 != 0) data_length++;

			vector<byte> raw_buffer(data_length,0);

			inet_pton(AF_INET6, ip_layer->GetSourceIP().c_str(), &raw_buffer[0]);
			inet_pton(AF_INET6, ip_layer->GetDestinationIP().c_str(), &raw_buffer[16]);
			word icmp_length = htonl(tot_length);
			memcpy(&raw_buffer[32],&icmp_length,sizeof(word));
			raw_buffer[39] = 0x3A;

			/* Setup the rest of the packet*/
			GetData(&raw_buffer[40]);

			checksum = CheckSum((unsigned short *)&raw_buffer[0],raw_buffer.size()/2);
		}

		else {
			PrintMessage(Portal::PrintCodes::PrintWarning,
					     "ICMPv6Layer::Portal()",
				         "Bottom Layer of ICMPv6 packet is not IPv6. Cannot calculate ICMPv6 checksum.");
			checksum = 0;
		}

		/* Set the checksum to zero */
		SetCheckSum(ntohs(checksum));
		ResetField(FieldCheckSum);
	}
}
