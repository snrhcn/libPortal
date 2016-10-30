#include "Payload.h"

using namespace std;
using namespace Portal;

void Payload::SetPayload (const byte *data, size_t ndata) {
	storage.clear();
	AddPayload(data,ndata);
}

/* Add more stuff to the payload */
void Payload::AddPayload (const byte* data, size_t ndata) {	
	storage.insert(storage.end(), data, data + ndata);
}

/* Set payload */
void Payload::SetPayload (const char *data) {
	size_t ndata = strlen(data);
	storage = vector<byte>(data, data + ndata);
}

/* Add more stuff to the payload */
void Payload::AddPayload (const char* data) {
	size_t ndata = strlen(data);
	storage.insert(storage.end(), data, data + ndata);
}

void Payload::SetPayload (const Payload& payload) {
	storage = payload.storage;
}

void Payload::AddPayload (const Payload& payload) {
	storage.insert(storage.end(), payload.storage.begin(), payload.storage.end());
}

/* Copy the data into the pointer and returns the number of bytes copied */
size_t Payload::GetPayload(byte* dst) const {
	return std::copy(storage.begin(), storage.end(), dst) - dst;
}

size_t Payload::GetPayload(byte* dst, size_t ndata) const {
	size_t size = GetSize();
	if(size > ndata) {
		size = ndata;
	}
	return std::copy(storage.begin(), storage.begin() + size, dst) - dst;
}

string Payload::GetString() const {
	return string(storage.begin(),storage.end());
}

/* Print Payload */
void Payload::Print(ostream& str) const{
	size_t size = GetSize();
	bool readable = 1;

	for (size_t i = 0 ; i < size ; i++) {
		if ( (!isprint(storage[i])) && (!iscntrl(storage[i])) ) {
			readable = 0;
			break;
		}
	}

	/* Print raw data in hexadecimal format */
	if (readable) {

		for(size_t i = 0 ; i < size ; i++) {
			if ((unsigned int)storage[i] == 0x09)
				str << "\\t";
			else if ((unsigned int)storage[i] == 0x0d)
				str  << "\\r";
			else if ((unsigned int)storage[i] == 0x0a)
				str  << "\\n";
			else if((unsigned int)storage[i] < 0x20) {
				str  << "\\x";
				str  << std::hex << (unsigned int)storage[i];
			} else
				str  << storage[i];
		}

	} else {

		for(size_t i = 0 ; i < size ; i++) {
			str  << "\\x";
			str  << std::hex << (unsigned int)storage[i];
		}

	}

}

void Payload::RawString(ostream& str) const {
	size_t size = GetSize();

	/* Print raw data in hexadecimal format */
	for(size_t i = 0 ; i < size ; i++) {
		str  << "\\x";
		str  << std::hex << (unsigned int)(storage)[i];
	}
}

void Payload::PrintChars(ostream& str) const {
	size_t size = GetSize();

	for(size_t i = 0 ; i < size ; i++)
		str  << (char)storage[i];
}

