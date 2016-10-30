#include "Ethernet.h"
#include "RawLayer.h"

using namespace Portal;
using namespace std;

void Ethernet::ReDefineActiveFields() {
}

void Ethernet::Portal() {
	/* Get transport layer protocol */
	if(TopLayer) {
		if(!IsFieldSet(FieldType)) {
			short_word network_layer = TopLayer->GetID();
			/* Set Protocol */
			if(network_layer != RawLayer::PROTO)
				SetType(network_layer);
			else
				SetType(0x0);

			ResetField(FieldType);
		}
	}
	else {
		PrintMessage(Portal::PrintCodes::PrintWarning,
				     "Ethernet::Portal()","No Network Layer Protocol associated with Ethernet Layer.");
	}
}

void Ethernet::ParseLayerData(ParseInfo* info) {
	short_word network_layer = GetType();
	info->next_layer = Protocol::AccessFactory()->GetLayerByID(network_layer);
}
