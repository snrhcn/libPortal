#include "NumericFields.h"
#include "../Utils/BitHandling.h"

#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;
using namespace Portal;

ByteField::ByteField(const std::string& name, size_t nword, size_t nbyte) :
		             Field<byte> (name,nword,nbyte*8,8),
                     nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

void ByteField::PrintValue(std::ostream& str) const {
	str << dec << (word)human;
}

FieldInfo* ByteField::Clone() const {
	ByteField* new_ptr = new ByteField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void ByteField::Write(byte* raw_data) const {
	raw_data[offset] = human;
}

void ByteField::Read(const byte* raw_data){
	human = raw_data[offset];
}

ByteField::~ByteField() { /* */ }

XByteField::XByteField(const std::string& name, size_t nword, size_t nbyte) :
		               ByteField(name,nword,nbyte)
                       { /* */ }

void XByteField::PrintValue(std::ostream& str) const {
	str << "0x" << hex << (word)human;
}

FieldInfo* XByteField::Clone() const {
	XByteField* new_ptr = new XByteField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

XByteField::~XByteField() { /* */ }

/* Control flags names */
const std::string TCPFlags::flags[] = {"FIN", "SYN", "RST", "PSH", "ACK", "URG", "ECE", "CWR"};

TCPFlags::TCPFlags(const std::string& name, size_t nword, size_t nbyte) :
		               ByteField(name,nword,nbyte)
                       { /* */ }

void TCPFlags::PrintValue(std::ostream& str) const {
	str << "( ";

	for(int i = 0 ; i < 8 ; i++) {
		int flag_shift = 1 << i;

		if (flag_shift & human)
			str << flags[i] << " ";
	}

	str << ")";
}

FieldInfo* TCPFlags::Clone() const {
	TCPFlags* new_ptr = new TCPFlags(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

TCPFlags::~TCPFlags() { /* */ }

ShortField::ShortField(const std::string& name, size_t nword, size_t nbyte) :
		             Field<short_word> (name,nword,nbyte*8,16),
                     nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

void ShortField::PrintValue(std::ostream& str) const {
	str << dec << (word)human;
}

FieldInfo* ShortField::Clone() const {
	ShortField* new_ptr = new ShortField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void ShortField::Write(byte* raw_data) const {
	short_word* ptr = (short_word*)(raw_data + offset);
	*ptr = htons(human);
}

void ShortField::Read(const byte* raw_data){
	short_word* ptr = (short_word*)(raw_data + offset);
	human = ntohs(*ptr);
}

ShortField::~ShortField() { /* */ }

ShortHostField::ShortHostField(const std::string& name, size_t nword, size_t nbyte) :
		             Field<short_word> (name,nword,nbyte*8,16),
                     nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

void ShortHostField::PrintValue(std::ostream& str) const {
	str << dec << (word)human;
}

FieldInfo* ShortHostField::Clone() const {
	ShortHostField* new_ptr = new ShortHostField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void ShortHostField::Write(byte* raw_data) const {
	short_word* ptr = (short_word*)(raw_data + offset);
	*ptr = human;
}

void ShortHostField::Read(const byte* raw_data){
	short_word* ptr = (short_word*)(raw_data + offset);
	human = *ptr;
}

ShortHostField::~ShortHostField() { /* */ }

ShortHostNetField::ShortHostNetField(const std::string& name, size_t nword, size_t nbyte) :
									ShortHostField(name,nword,nbyte)
                         { /* */ }

void ShortHostNetField::Read(const byte* raw_data){
	short_word* ptr = (short_word*)(raw_data + offset);
	human = ntohs(*ptr);
}

FieldInfo* ShortHostNetField::Clone() const {
	ShortHostNetField* new_ptr = new ShortHostNetField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

ShortHostNetField::~ShortHostNetField() { /* */ }

XShortField::XShortField(const std::string& name, size_t nword, size_t nbyte) :
						 ShortField(name,nword,nbyte)
                         { /* */ }

void XShortField::PrintValue(std::ostream& str) const {
	str << "0x" << hex << (word)human;
}

FieldInfo* XShortField::Clone() const {
	XShortField* new_ptr = new XShortField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

XShortField::~XShortField() { /* */ }

WordField::WordField(const std::string& name, size_t nword, size_t nbyte) :
		             Field<word> (name,nword,nbyte*8,32),
                     nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

void WordField::PrintValue(std::ostream& str) const {
	str << dec << (word)human;
}

FieldInfo* WordField::Clone() const {
	WordField* new_ptr = new WordField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void WordField::Write(byte* raw_data) const {
	word* ptr = (word*)(raw_data + offset);
	*ptr = htonl(human);
}

void WordField::Read(const byte* raw_data){
	word* ptr = (word*)(raw_data + offset);
	human = ntohl(*ptr);
}

WordField::~WordField() { /* */ }

WordHostField::WordHostField(const std::string& name, size_t nword, size_t nbyte) :
		             Field<word> (name,nword,nbyte*8,32),
                     nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

void WordHostField::PrintValue(std::ostream& str) const {
	str << dec << (word)human;
}

FieldInfo* WordHostField::Clone() const {
	WordHostField* new_ptr = new WordHostField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void WordHostField::Write(byte* raw_data) const {
	word* ptr = (word*)(raw_data + offset);
	*ptr = human;
}

void WordHostField::Read(const byte* raw_data){
	word* ptr = (word*)(raw_data + offset);
	human = *ptr;
}

WordHostField::~WordHostField() { /* */ }

XWordField::XWordField(const std::string& name, size_t nword, size_t nbyte) :
						 WordField(name,nword,nbyte)
                         { /* */ }

void XWordField::PrintValue(std::ostream& str) const {
	str << "0x" << hex << (word)human;
}

FieldInfo* XWordField::Clone() const {
	XWordField* new_ptr = new XWordField(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

XWordField::~XWordField() { /* */ }

Int64Field::Int64Field(const std::string& name, size_t nword, size_t nbyte) :
						Field<uint64_t> (name,nword,nbyte*8,64),
						nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

void Int64Field::PrintValue(std::ostream& str) const {
	str << GetName() << " = " << dec << (uint64_t)human;
}

FieldInfo* Int64Field::Clone() const {
	Int64Field* new_ptr = new Int64Field(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void Int64Field::Write(byte* raw_data) const {
	uint64_t* ptr = (uint64_t*)(raw_data + offset);
	*ptr = htonll(human);
}

void Int64Field::Read(const byte* raw_data){
	uint64_t* ptr = (uint64_t*)(raw_data + offset);
	human = ntohll(*ptr);
}

Int64Field::~Int64Field() { /* */ }
