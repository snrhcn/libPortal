#include "IP.h"
#include "RawLayer.h"
#include "IPOption.h"

using namespace std;
using namespace Portal;

const size_t MAXOPT = 40;
const size_t IPHDRSIZE = 20;

void IP::ReDefineActiveFields() {
}

void IP::Portal() {

	size_t tot_length = GetRemainingSize();

	/* First, put the total length on the header */
	if (!IsFieldSet(FieldTotalLength)) {
		SetTotalLength(tot_length);
		ResetField(FieldTotalLength);
	}

	/* Array for the option data */
	byte ip_data[IPHDRSIZE + MAXOPT];
	memset(ip_data, 0, IPHDRSIZE + MAXOPT);

	size_t option_length = 0;

	/* Check the options and update header length */
	if (!IsFieldSet(FieldHeaderLength)) {
		Layer* top_layer = GetTopLayer();
		if(top_layer) {
			while( top_layer && ((top_layer->GetID() >> 8) == (IPOption::PROTO >> 8))) {
				size_t last_opt_length = option_length;
				/* Update option length */
				option_length += top_layer->GetSize();
				/* Get the option data */
				if(option_length <= MAXOPT) top_layer->GetRawData(ip_data + IPHDRSIZE + last_opt_length);
				/* Go to next layer */
                top_layer = top_layer->GetTopLayer();
			}
		}

		if(option_length%4 != 0)
			PrintMessage(Portal::PrintCodes::PrintWarning,
					     "IP::Portal()",
				         "Option size is not padded to a multiple of 4 bytes.");

		SetHeaderLength(5 + option_length/4);
		ResetField(FieldHeaderLength);

		/* Get transport layer protocol */
		if(top_layer) {
			if(!IsFieldSet(FieldProtocol)) {
				short_word transport_layer = top_layer->GetID();
				/* Set Protocol */
				if(transport_layer != RawLayer::PROTO)
					SetProtocol(transport_layer);
				else
					SetProtocol(0x0);

				ResetField(FieldProtocol);
			}
		}
		else {
			PrintMessage(Portal::PrintCodes::PrintWarning,
					     "IP::Portal()","No Transport Layer Protocol associated with IP Layer.");
		}
	}

	size_t ip_length = option_length + 20;
	if(ip_length > (MAXOPT + IPHDRSIZE) ) ip_length = MAXOPT + IPHDRSIZE;

	if (!IsFieldSet(FieldCheckSum)) {
		/* Compute the 16 bit checksum */
		SetCheckSum(0);
		GetRawData(ip_data);
		/* Calculate the checksum */
		short_word checksum = CheckSum((unsigned short *)ip_data,ip_length/2);
		SetCheckSum(ntohs(checksum));
		ResetField(FieldCheckSum);
	}
}

string IP::MatchFilter() const {
	return "ip and dst host " + GetSourceIP() + " and src host " + GetDestinationIP();
}

void IP::ParseLayerData(ParseInfo* info) {
	size_t total_length = this->GetTotalLength() - this->GetSize();
	size_t total_data = info->total_size - info->offset;

	/* Detect ethernet padding */
	if(total_data > total_length) {
		info->total_size -= (total_data - total_length);
	}

	/* Verify if there are options on the IP header */
	size_t IP_word_size = GetHeaderLength();
	size_t IP_opt_size = 0;

	if(IP_word_size > 5) IP_opt_size = 4 * (IP_word_size - 5);

	short_word network_layer = GetProtocol();

	/* We have a valid set of options */
	if (IP_opt_size > 0) {
		/* Extra information for IP options */
		IPOptionLayer::ExtraInfo* extra_info = new IPOptionLayer::ExtraInfo;
		extra_info->optlen = IP_opt_size;
		extra_info->next_layer = Protocol::AccessFactory()->GetLayerByID(network_layer);

		/* Information for the decoder */
		int opt = (info->raw_data + info->offset)[0];
		info->next_layer = IPOptionLayer::Build(opt);
		info->extra_info = extra_info;
	} else {
		info->next_layer = Protocol::AccessFactory()->GetLayerByID(network_layer);
	}
}
