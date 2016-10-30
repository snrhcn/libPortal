#include "SLL.h"

using namespace Portal;
using namespace std;

void SLL::ReDefineActiveFields() {
}

void SLL::Portal() {
	/* Get transport layer protocol */
	if(TopLayer) {
		if(!IsFieldSet(FieldProtocol)) {
			short_word network_layer = TopLayer->GetID();
			/* Set Protocol */
			if(network_layer != 0xfff1)
				SetProtocol(network_layer);
			else
				SetProtocol(0x0);

			ResetField(FieldProtocol);
		}
	}
	else {
		PrintMessage(Portal::PrintCodes::PrintWarning,
				     "SSL::Portal()","No Network Layer Protocol associated with SLL Layer.");
	}
}

void SLL::ParseLayerData(ParseInfo* info) {
	short_word network_layer = GetProtocol();
	info->next_layer = Protocol::AccessFactory()->GetLayerByID(network_layer);
}
