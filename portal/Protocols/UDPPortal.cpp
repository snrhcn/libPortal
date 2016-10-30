#include "UDP.h"
#include "IP.h"
#include "IPv6.h"

using namespace Portal;
using namespace std;

void UDP::ReDefineActiveFields() {

}

void UDP::Portal() {

	/* Bottom layer name */
	short_word bottom_layer = 0;

	/* Checksum of UDP packet */
	short_word checksum;

	size_t tot_length = GetRemainingSize();

	/* Set the Length of the UDP packet */
	if (!IsFieldSet(FieldLength)) {
		SetLength(tot_length);
		ResetField(FieldLength);
	}

	/* Bottom layer name (look for IPs layers) */
	Layer* bottom_ptr = GetBottomLayer();

	while(bottom_ptr && (bottom_ptr->GetID() != IP::PROTO) && (bottom_ptr->GetID() != IPv6::PROTO))
        bottom_ptr = bottom_ptr->GetBottomLayer();

	if(bottom_ptr)  bottom_layer = bottom_ptr->GetID();

	if (!IsFieldSet(FieldCheckSum)) {

		/* Set the checksum to zero */
		SetCheckSum(0x0);

		if(bottom_layer == IP::PROTO) {

			/* It's OK */
			IP* ip_layer = dynamic_cast<IP*>(bottom_ptr);

			size_t data_length = 12 + tot_length;

			if(data_length%2 != 0) data_length++;

			vector<byte> raw_buffer(data_length,0);

			inet_pton(AF_INET, ip_layer->GetSourceIP().c_str(), &raw_buffer[0]);
			inet_pton(AF_INET, ip_layer->GetDestinationIP().c_str(), &raw_buffer[4]);
			raw_buffer[9] = IPPROTO_UDP;
			short_word udp_length = htons(tot_length);
			memcpy(&raw_buffer[10],&udp_length,sizeof(short_word));

			/* Setup the rest of the UDP datagram */
			GetData(&raw_buffer[12]);

			checksum = CheckSum((unsigned short *)&raw_buffer[0],raw_buffer.size()/2);

		}

		else if(bottom_layer == IPv6::PROTO) {
			/* It's OK */
			IPv6* ip_layer = dynamic_cast<IPv6*>(bottom_ptr);

			size_t data_length = 40 + tot_length;

			if(data_length%2 != 0) data_length++;

			vector<byte> raw_buffer(data_length,0);

			inet_pton(AF_INET6, ip_layer->GetSourceIP().c_str(), &raw_buffer[0]);
			inet_pton(AF_INET6, ip_layer->GetDestinationIP().c_str(), &raw_buffer[16]);
			word udp_length = htonl(tot_length);
			memcpy(&raw_buffer[32],&udp_length,sizeof(word));
			raw_buffer[39] = IPPROTO_UDP;

			/* Setup the rest of the UDP datagram */
			GetData(&raw_buffer[40]);

			checksum = CheckSum((unsigned short *)&raw_buffer[0],raw_buffer.size()/2);
		}

		else {
			PrintMessage(Portal::PrintCodes::PrintWarning,
					     "UDP::Portal()",
				         "Bottom Layer of UDP packet is not IP. Cannot calculate UDP checksum.");
			checksum = 0;
		}

		/* Set the checksum to zero */
		SetCheckSum(ntohs(checksum));
		ResetField(FieldCheckSum);
	}
}

string UDP::MatchFilter() const {
	char src_port[6];
	char dst_port[6];
	sprintf(src_port,"%d", GetSrcPort());
	sprintf(dst_port,"%d", GetDstPort());
	std::string ret_str = "udp and dst port " + std::string(src_port) + " and src port " + std::string(dst_port);
	return ret_str;
}
