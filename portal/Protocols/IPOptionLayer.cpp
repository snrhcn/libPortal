#include "IPOptionLayer.h"
#include "IPOption.h"
#include "IPOptionPad.h"
#include "IPOptionPointer.h"
#include "IPOptionTraceroute.h"
#include <netinet/ip.h>

using namespace Portal;

IPOptionLayer* IPOptionLayer::Build(int opt) {

	switch(opt) {

	case IPOPT_EOL :
		return new IPOptionPad;
		break;
	case IPOPT_NOP:
		return new IPOptionPad;
		break;
	case 0x52:
		return new IPOptionTraceroute;
		break;
	case IPOPT_LSRR:
		return new IPOptionLSRR;
		break;
	case IPOPT_RR:
		return new IPOptionRR;
		break;
	case IPOPT_SSRR:
		return new IPOptionSSRR;
		break;

	}

	/* Generic Option Header */
	return new IPOption;

}

void IPOptionLayer::ParseLayerData(ParseInfo* info) {
	/* Update the information of the IP options */
	IPOptionLayer::ExtraInfo* extra_info =
		static_cast<IPOptionLayer::ExtraInfo*>(info->extra_info);
	if(!extra_info) {
		info->top = 1;
		return;
	}
	extra_info->optlen -= GetSize();
	if(extra_info->optlen > 0) {
		/* Get the option type */
		int opt = (info->raw_data + info->offset)[0];
		info->next_layer = Build(opt);
	}  else {
		info->next_layer = extra_info->next_layer;
		delete extra_info;
		extra_info = 0;
	}
}



