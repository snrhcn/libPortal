#include "IPv6MobileRoutingHeader.h"

using namespace Portal;
using namespace std;

void IPv6MobileRoutingHeader::Portal() {

    if (!IsFieldSet(FieldSegmentLeft)) {
        SetSegmentLeft(1);
        ResetField(FieldSegmentLeft);
    }

    if (!IsFieldSet(FieldHeaderExtLen)) {
        SetHeaderExtLen(2);
        ResetField(FieldHeaderExtLen);
    }

    if (!IsFieldSet(FieldReserved)) {
        SetReserved(0);
        ResetField(FieldReserved);
    }

    IPv6RoutingHeader::Portal();
}

