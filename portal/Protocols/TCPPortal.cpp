#include "TCP.h"
#include "IP.h"
#include "IPv6.h"
#include "TCPOption.h"

using namespace Portal;
using namespace std;

const byte TCP::FIN = 1 << 0;
const byte TCP::SYN = 1 << 1;
const byte TCP::RST = 1 << 2;
const byte TCP::PSH = 1 << 3;
const byte TCP::ACK = 1 << 4;
const byte TCP::URG = 1 << 5;
const byte TCP::ECE = 1 << 6;
const byte TCP::CWR = 1 << 7;

size_t TCP::ComputeOptionSize() const {
    Layer* top_layer = GetTopLayer();
    size_t option_length = 0;

    if(top_layer) {
        while(top_layer
              && ((top_layer->GetID() >> 8) == (TCPOption::PROTO >> 8))) {
            option_length += top_layer->GetSize();
            top_layer = top_layer->GetTopLayer();
        }
    }

    if(option_length%4 != 0)
        PrintMessage(Portal::PrintCodes::PrintWarning,
                     "TCP::Portal()",
                     "Option size is not padded to a multiple of 4 bytes.");
    return option_length;
}

void TCP::Portal() {

	short_word bottom_layer = 0;

	/* Checksum of UDP packet */
	short_word checksum;

	/* Check the options and update header length */
	if (!IsFieldSet(FieldDataOffset)) {
        SetDataOffset(5 + ComputeOptionSize()/4);
		ResetField(FieldDataOffset);
	}

	size_t tot_length = GetRemainingSize();

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
			raw_buffer[9] = IPPROTO_TCP;
			short_word tcp_length = htons(tot_length);
			memcpy(&raw_buffer[10],&tcp_length,sizeof(short_word));

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
			word tcp_length = htonl(tot_length);
			memcpy(&raw_buffer[32],&tcp_length,sizeof(word));
			raw_buffer[39] = IPPROTO_TCP;

			/* Setup the rest of the UDP datagram */
			GetData(&raw_buffer[40]);

			checksum = CheckSum((unsigned short *)&raw_buffer[0],raw_buffer.size()/2);
		}

		else {
			PrintMessage(Portal::PrintCodes::PrintWarning,
					     "TCP::Portal()",
				         "Bottom Layer of TCP packet is not IP. Cannot calculate TCP checksum.");
			checksum = 0;
		}

		/* Set the checksum to zero */
		SetCheckSum(ntohs(checksum));
		ResetField(FieldCheckSum);
	}
}

string TCP::MatchFilter() const {
	char src_port[6];
	char dst_port[6];
	sprintf(src_port,"%d", GetSrcPort());
	sprintf(dst_port,"%d", GetDstPort());
	std::string ret_str = "tcp and dst port " + std::string(src_port) + " and src port " + std::string(dst_port);
	return ret_str;
}

void TCP::ParseLayerData(ParseInfo* info) {
	/* Verify if there are options on the IP header */
	size_t TCP_word_size = GetDataOffset();
	/* Get options size */
	size_t TCP_opt_size = 0;
	if(TCP_word_size > 5) TCP_opt_size = 4 * (TCP_word_size - 5);

	/* We have a valid set of options */
	if (TCP_opt_size > 0) {
		/* Extra information for TCP options */
		TCPOptionLayer::ExtraInfo* extra_info = new TCPOptionLayer::ExtraInfo;
		extra_info->optlen = TCP_opt_size;
		extra_info->next_layer = 0;
        extra_info->header_len = TCP_word_size;

		/* Information for the decoder */
		int opt = (info->raw_data + info->offset)[0];
		info->next_layer = TCPOptionLayer::Build(opt, info);
		info->extra_info = extra_info;
	} else
		info->next_layer = 0;

}
