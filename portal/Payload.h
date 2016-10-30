#ifndef PAYLOAD_H_
#define PAYLOAD_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "Types.h"

namespace Portal {

	class Payload {

	protected:
		/* Readable payload */
		byte IsReadable;

		/* Container of data */
		std::vector<byte> storage;

		/* Clear the Payload */
		void clear () { storage.clear(); };

		/* Initial reserved size */
		static const size_t reserved = 128;

	public:

		Payload() : IsReadable(1) {
			/* Reserve */
			storage.reserve(reserved);
		};

		/* Copy constructor */
		Payload(const Payload& payload) : IsReadable(payload.IsReadable), storage(payload.storage) { };

		Payload(const std::vector<byte>& raw_data) : IsReadable(1) {
			storage.reserve(reserved);
			SetPayload(&raw_data[0],raw_data.size());
		};

		/* Equal from a general Layer */
		Payload& operator=(const Payload& payload) {
			storage = payload.storage;
			IsReadable = payload.IsReadable;
			return *this;
		}

		/* Get size in bytes of the payload */
		size_t GetSize() const { return storage.size(); };

		/* Set payload */
		void SetPayload (const char *data);
		void SetPayload (const Payload& payload);
		void SetPayload (const byte *data, size_t ndata);

		/* Add more stuff to the payload */
		void AddPayload (const char* data);
		void AddPayload (const Payload& payload);
		void AddPayload (const byte* data, size_t ndata);

		/* Copy the data into the pointer and returns the number of bytes copied */
		size_t GetPayload(byte* dst) const;

		/* Copy the data into the pointer (no more than ndata) and returns the number of bytes copied */
		size_t GetPayload(byte* dst, size_t ndata) const;

		/* Get payload as a STL string */
		std::string GetString() const;

		/* Clear the payload */
		void Clear() { storage.clear(); };

		/* Print characters one by one */
		void PrintChars(std::ostream& str = std::cout) const;

		/* Print a raw string of the payload */
		void RawString(std::ostream& str = std::cout) const;

		/* Print Payload */
		virtual void Print(std::ostream& str = std::cout) const;

		/* Return a constant reference to the container */
		const std::vector<byte>& GetContainer() const { return storage; };

		/* Get raw pointer */
		const byte* GetRawPointer() const { return (const byte*)&storage[0]; };

		virtual ~Payload() { /* */ };
	};

}


#endif /* PAYLOAD_H_ */
