#include "IPv6RoutingHeader.h"
#include "IPv6SegmentRoutingHeader.h"
#include "IPv6MobileRoutingHeader.h"
#include "IPv6.h"


using namespace Portal;
using namespace std;


IPv6RoutingHeader* IPv6RoutingHeader::Build(int type) {
    switch(type) {
        case 0: /* Routing Header Type 0 -- DEPRECATED */
        case 1: /* Nimrod -- DEPRECATED 2009-05-06 */
            return new IPv6RoutingHeader;
        case 2: /* IPv6 mobility -- rfc6275 */
            return new IPv6MobileRoutingHeader;
        case 3: /* RPL -- rfc6554 */
            return new IPv6RoutingHeader;
        case 4: /* Segment Routing -- draft-previdi-6man-segment-routing-header */
            return new IPv6SegmentRoutingHeader;
        case 253: /* IETF Experimental values -- rfc4727 */
        case 254: /* IETF Experimental values -- rfc4727 */
            return new IPv6RoutingHeader;
    }
    /* Defaulting to an opaque layer */
    return new IPv6RoutingHeader;
}

size_t IPv6RoutingHeader::GetRoutingPayloadSize() const {
    /* Everything in type data + the required _unused_ 4 bytes of the header
     * that will change depending on the ehader type */
    return GetHeaderExtLen() * 8 + 4;
}

void IPv6RoutingHeader::FillRoutingPayload(byte *payload) const {
    /* Nothing to put in the payload, just nullify it */
    memset(payload, 0, GetRoutingPayloadSize());
}

void IPv6RoutingHeader::Portal() {
    /* Skipping HdrExtLen and SegmentsLeft because these have sane default
     * for an opaque header.
     */
    if (!IsFieldSet(FieldRoutingType)) {
        SetRoutingType(protoID & 0xFF);
        ResetField(FieldRoutingType);
    }

    if (!IsFieldSet(FieldNextHeader)) {
        if (TopLayer) {
            SetNextHeader(IPv6::GetIPv6NextHeader(TopLayer->GetID()));
            ResetField(FieldNextHeader);
        } else {
            PrintMessage(Portal::PrintCodes::PrintWarning,
                "IPv6RoutingHeader::Portal()", "No transport layer protocol.");
        }
    }

    size_t payload_size = GetRoutingPayloadSize();
    if (payload_size) {
        byte* raw_payload = new byte[payload_size];
        FillRoutingPayload(raw_payload);
        SetPayload(raw_payload, payload_size);
        delete[] raw_payload;
    }
}

void IPv6RoutingHeader::ParseLayerData(ParseInfo *info) {
    /* Save all fields */
    Fields.ApplyAll(&FieldInfo::FieldSet);
    const size_t payload_size = GetRoutingPayloadSize();
    if (payload_size) {
        /* Save _extra_ data of this header */
        SetPayload(info->raw_data + info->offset, payload_size);
        /* Increment offset accordingly */
        info->offset += payload_size;
    }
    info->next_layer = IPv6::GetNextLayer(info, GetNextHeader());
}

