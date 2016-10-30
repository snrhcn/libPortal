#include "ICMPExtensionMPLS.h"
#include "ICMPExtensionObject.h"

using namespace Portal;
using namespace std;

void ICMPExtensionMPLS::ReDefineActiveFields() {
}

void ICMPExtensionMPLS::Portal() {
    SetPayload(NULL, 0);
    Layer* layer = GetTopLayer();
    if (!layer || layer->GetName() != GetName())
        SetBottomOfStack(1);
    else
        SetBottomOfStack(0);
}

void ICMPExtensionMPLS::ParseLayerData(ParseInfo* info) {
	if(GetBottomOfStack())
		info->next_layer = Protocol::AccessFactory()->GetLayerByID(ICMPExtensionObject::PROTO);
	else
		info->next_layer = Protocol::AccessFactory()->GetLayerByID(ICMPExtensionMPLS::PROTO);

}
