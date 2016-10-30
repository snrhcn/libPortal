#include "TCPOption.h"
#include "TCPOptionLayer.h"
#include "TCPOptionMaxSegSize.h"
#include "TCPOptionPad.h"
#include "TCPOptionTimestamp.h"
#include "TCPOptionWindowScale.h"
#include "TCPOptionMPTCP.h"
#include <netinet/tcp.h>

using namespace Portal;

#ifndef TCPOPT_EOL
	#define TCPOPT_EOL		0
#endif
#ifndef TCPOPT_NOP
	#define TCPOPT_NOP		1
#endif
#ifndef TCPOPT_MAXSEG
	#define TCPOPT_MAXSEG		2
#endif
#ifndef TCPOPT_WINDOW
	#define TCPOPT_WINDOW		3
#endif
#ifndef TCPOPT_SACK_PERMITTED
	#define TCPOPT_SACK_PERMITTED	4		/* Experimental */
#endif
#ifndef TCPOPT_SACK
	#define TCPOPT_SACK		5		/* Experimental */
#endif
#ifndef TCPOPT_TIMESTAMP
	#define TCPOPT_TIMESTAMP	8
#endif

TCPOptionLayer* TCPOptionLayer::Build(int opt, ParseInfo *info) {

	switch(opt) {

	case TCPOPT_EOL            : return new TCPOptionPad;
	case TCPOPT_NOP            : return new TCPOptionPad;
	case TCP_MAXSEG            : return new TCPOptionMaxSegSize;
	case TCPOPT_TIMESTAMP      : return new TCPOptionTimestamp;
	case TCPOPT_SACK_PERMITTED : return new TCPOptionSACKPermitted;
	case TCPOPT_SACK           : return new TCPOptionSACK;
	case TCPOPT_WINDOW         : return new TCPOptionWindowScale;
	case TCPOPT_TFO            : return new TCPOptionFastOpen;
    case TCPOPT_MPTCP          :
		return TCPOptionMPTCP::Build((info->raw_data + info->offset)[2] >> 4);
    case TCPOPT_EDO            :
		/* We're not extracting the length to determine the subtype here,
		 * as it messes with the perceived size in ParseLayerData */
		return new TCPOptionEDO;
    }

	/* Generic Option Header */
	return new TCPOption;
}

void TCPOptionLayer::ParseLayerData(ParseInfo* info) {
	/* Update the information of the IP options */
	ExtraInfo* extra_info = static_cast<ExtraInfo*>(info->extra_info);
	if(!extra_info) {
		info->top = 1;
		return;
	}

	extra_info->optlen -= GetSize();
	if(extra_info->optlen > 0) {
		/* Get the option type */
		int opt = (info->raw_data + info->offset)[0];
		info->next_layer = Build(opt, info);
	}  else {
		info->next_layer = extra_info->next_layer;
		delete extra_info;
		extra_info = 0;
	}
}
