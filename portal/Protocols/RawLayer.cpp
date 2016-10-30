#include "RawLayer.h"

using namespace std;
using namespace Portal;

RawLayer::RawLayer() {
	/* Name of the protocol */
	SetName("RawLayer");
	/* Set protocol Number */
	SetprotoID(0xfff1);

	DefineProtocol();
}

/* Constructor from raw data */
RawLayer::RawLayer(const byte* data, size_t size) {
	/* Name of the protocol */
	SetName("RawLayer");
	/* Set protocol Number */
	SetprotoID(0xfff1);

	DefineProtocol();

	SetPayload(data,size);
}

/* Constructor from string */
RawLayer::RawLayer(const char* str) {
	/* Name of the protocol */
	SetName("RawLayer");
	/* Set protocol Number */
	SetprotoID(0xfff1);

	DefineProtocol();

	SetPayload(str);
}

/* Constructor from a general Layer */
RawLayer::RawLayer(const Layer& layer){
	/* Name of the protocol */
	SetName("RawLayer");
	/* Set protocol Number */
	SetprotoID(0xfff1);

	DefineProtocol();

	/* Get the size of the layer */
	size_t layer_size = layer.GetSize();
	/* Allocate memory */
	byte* data = new byte[layer_size];

	/* Put data into the buffer */
	layer.GetRawData(data);

	/* Now, set the payload */
	SetPayload(data,layer_size);

	delete [] data;
}

/* Equal from string */
RawLayer& RawLayer::operator=(const char* str) {
	SetPayload(str);
	return *this;
}

/* Equal from a general Layer */
RawLayer& RawLayer::operator=(const Layer& layer) throw () {
	/* Get the size of the layer */
	size_t layer_size = layer.GetSize();
	/* Allocate memory */
	byte* data = new byte[layer_size];

	/* Put data into the buffer */
	layer.GetRawData(data);

	/* Now, set the payload */
	SetPayload(data,layer_size);

	delete [] data;

	return *this;
}

const RawLayer RawLayer::operator+(const RawLayer& right) const{
	/* Get both size */
	size_t right_size = right.GetSize();
	size_t left_size = GetSize();

	/* Allocate buffer */
	byte* buffer = new byte[right_size + left_size];

	/* Get data */
	size_t copied = GetRawData(buffer);
	right.GetRawData(buffer + copied);

	RawLayer ret_layer = RawLayer(buffer, right_size + left_size);

	delete [] buffer;

	return ret_layer;
}

void RawLayer::ParseLayerData(ParseInfo* info) {
	/* Get the extra information, this is s sandwich RawLayer */
	RawLayer::ExtraInfo* extra_info =
		static_cast<RawLayer::ExtraInfo*>(info->extra_info);
	if(!extra_info) {
		/* Set payload */
		SetPayload(info->raw_data,info->total_size - info->offset);
		info->offset = info->total_size;
		/* Set next layer */
		info->top = 1;
		return;
	}
	/* Set payload */
	SetPayload(extra_info->raw_data,extra_info->nbytes);
	info->offset += extra_info->nbytes;
	/* Set next layer */
	info->next_layer = extra_info->next_layer;

	/* Delete structure */
	delete extra_info;
	extra_info = 0;
}

Pad::Pad(byte value, size_t times) {
    byte* pad_data = new byte[times];
    memset(pad_data,value,times*sizeof(byte));
    SetPayload(pad_data,times);
    delete pad_data;
}
