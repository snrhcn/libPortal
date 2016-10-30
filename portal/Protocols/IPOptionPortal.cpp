#include "IPOption.h"

using namespace Portal;
using namespace std;

void IPOption::ReDefineActiveFields() {
}

void IPOption::Portal() {
	if(!IsFieldSet(FieldLength)) {
		SetLength(2 + GetPayloadSize());
		ResetField(FieldLength);
	}
}

void IPOption::ParseLayerData(ParseInfo* info) {
	/* Update the information of the IP options */
	IPOptionLayer::ExtraInfo* extra_info =
		static_cast<IPOptionLayer::ExtraInfo*>(info->extra_info);

	if(!extra_info) {
		/* Is trying to parse from an IPOption layer? Get the hell out of here... */
		info->top = 1;
		return;
	}

	int optlen = GetLength();
	if(optlen > extra_info->optlen) optlen = extra_info->optlen;
	if(optlen > 2) {
		SetPayload(info->raw_data + info->offset, optlen - 2);
		info->offset += optlen - 2;
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
