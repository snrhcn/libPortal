#include "ICMPExtension.h"
#include "ICMPExtensionObject.h"

using namespace Portal;
using namespace std;

void ICMPExtension::ReDefineActiveFields() {
}

void ICMPExtension::Portal() {
    SetPayload(NULL, 0);

	if (!IsFieldSet(FieldCheckSum) || (GetCheckSum() == 0)) {

		/* Total size */
		size_t total_size = GetRemainingSize();
		if ( (total_size%2) != 0 ) total_size++;

		byte* buff_data = new byte[total_size];

		buff_data[total_size - 1] = 0x00;

		/* Compute the 16 bit checksum */
		SetCheckSum(0);

		GetData(buff_data);
		short_word checksum = CheckSum((unsigned short *)buff_data,total_size/2);
		SetCheckSum(ntohs(checksum));
		ResetField(FieldCheckSum);

		delete [] buff_data;

	}
}

void ICMPExtension::ParseLayerData(ParseInfo* info) {
	info->next_layer = Protocol::AccessFactory()->GetLayerByID(ICMPExtensionObject::PROTO);
}
