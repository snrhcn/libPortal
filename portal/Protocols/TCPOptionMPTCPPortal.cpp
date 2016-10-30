#include "TCPOptionMPTCP.h"
#include "../Utils/BitHandling.h"

using namespace Portal;
using namespace std;

void TCPOptionMPTCP::Portal() {
	SetLength(GetLength() + GetPayloadSize());
}

void TCPOptionMPTCPCapable::SetReceiverKey(const uint64_t& value) {
	word* data = new word[2];
	*((uint64_t *)data) = htonll(value);

	SetPayload((const byte*)data,sizeof(uint64_t));
}

uint64_t TCPOptionMPTCPCapable::GetReceiverKey() const {
	size_t payload_size = GetPayloadSize();
	if( payload_size > 0) {
		const byte* raw_data = GetPayload().GetRawPointer();
		return ntohll(*(const uint64_t *)(raw_data));
	}
	return 0;
}

TCPOptionLayer* TCPOptionMPTCP::Build(byte subopt) {

	switch(subopt) {
	case 0:
		return new TCPOptionMPTCPCapable;
	case 1:
		return new TCPOptionMPTCPJoin;
	}

	/* Generic Option Header */
	return new TCPOption;
}
