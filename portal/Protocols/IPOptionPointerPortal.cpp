#include "IPOptionPointer.h"

using namespace Portal;
using namespace std;

void IPOptionPointer::ReDefineActiveFields() {
}

void IPOptionPointer::Portal() {
	if(!IsFieldSet(FieldLength)) {
		SetLength(3 + GetPayloadSize());
		ResetField(FieldLength);
	}
}

void IPOptionPointer::ParseLayerData(ParseInfo* info) {
	/* Update the information of the IP options */
	IPOptionLayer::ExtraInfo* extra_info = static_cast<IPOptionLayer::ExtraInfo*>(info->extra_info);
	if(!extra_info) {
		info->top = 1;
		return;
	}

	int optlen = GetLength();
	if(optlen > extra_info->optlen) optlen = extra_info->optlen;
	if(optlen > 3) {
		SetPayload(info->raw_data + info->offset, optlen - 3);
		info->offset += optlen - 3;
	}
	extra_info->optlen -= GetSize();
	if(extra_info->optlen > 0) {
		/* Get the option type */
		int opt = (info->raw_data + info->offset)[0];
		info->next_layer = Build(opt);
	} else {
		info->next_layer = extra_info->next_layer;
		delete extra_info;
		extra_info = 0;
	}
}
