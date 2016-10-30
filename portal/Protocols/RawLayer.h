#ifndef RAWLAYER_H_
#define RAWLAYER_H_

#include "../Layer.h"

namespace Portal {

		class RawLayer : public Layer {

			/* Define the field of the IP layer */
			void DefineProtocol() {
				/* No fields */
			};

			Constructor GetConstructor() const {
				return RawLayer::RawLayerConstFunc;
			};

			static Layer* RawLayerConstFunc() {
				return new RawLayer;
			};

			/* Copy Portald packet to buffer_data */
			void Portal () {
				/* Nothing to Portal */
			};

			void ParseLayerData(ParseInfo* info);

		public:

			struct ExtraInfo {
				/* Data */
				const byte* raw_data;
				/* Number of bytes to push on the RawLayer payload */
				size_t nbytes;
				/* Next layer */
				Layer* next_layer;

				ExtraInfo(const byte* raw_data, size_t nbytes, Layer* next_layer) :
				          raw_data(raw_data), nbytes(nbytes), next_layer(next_layer) {};
			};

			enum { PROTO = 0xfff1 };

			RawLayer();

			/* Constructor from raw data */
			RawLayer(const byte* data, size_t size);

			/* Constructor from string */
			RawLayer(const char* str);

			/* Constructor from a general Layer */
			RawLayer(const Layer& layer);

			/* Equal from string */
			RawLayer& operator=(const char* str);

			/* Equal from a general Layer */
			RawLayer& operator=(const Layer& layer) throw ();

			/* Concatenate to raw layers */
			const RawLayer operator+(const RawLayer& right) const;

			virtual ~RawLayer() { };
		};

		class Pad : public RawLayer {

		public:
			Pad(byte value, size_t times);
			~Pad() { /* */ };
		};

}

#endif /* RAWLAYER_H_ */
