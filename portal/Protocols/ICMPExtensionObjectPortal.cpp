#include "ICMPExtensionObject.h"

using namespace Portal;
using namespace std;

/* Classes (ClassNum) */
const byte ICMPExtensionObject::MPLS = 1;

/* Types (CType) */
/* +++ MPLS +++ */
const byte ICMPExtensionObject::MPLSReserved = 0;
const byte ICMPExtensionObject::MPLSIncoming = 1;

void ICMPExtensionObject::ReDefineActiveFields() {
}

void ICMPExtensionObject::Portal() {
    SetPayload(NULL, 0);


    Layer* layer = GetTopLayer();

    /* Set the extension object type/code */
    if (layer) {
        if (layer->GetName() == "ICMPExtensionMPLS") {
            SetClassNum(MPLS);
            SetCType(MPLSIncoming);
        } else {
            SetClassNum(0);
            SetCType(0);
        }
    }

    /* Set the extension object length */
    word length = 0;
    while (layer && layer->GetName() != "ICMPExtensionObject") {
        length += layer->GetSize();
        /* Trick to make every sibling class a friend :) */
        layer = layer->GetTopLayer();
    }
    SetLength(GetSize() + length);
}

std::string ICMPExtensionObject::GetClassName() const {
    word classnum = GetClassNum();
    switch (classnum) {
    case MPLS: return "ICMPExtensionMPLS";
    default: return "";
    }
}

void ICMPExtensionObject::ParseLayerData(ParseInfo* info) {
    std::string icmp_extension_object_name = GetClassName();
    /* Get the extension layer */
    info->next_layer = Protocol::AccessFactory()->GetLayerByName(icmp_extension_object_name);
}
