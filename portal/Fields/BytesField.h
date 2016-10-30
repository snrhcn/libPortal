#ifndef BYTESFIELD_H_
#define BYTESFIELD_H_

#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>

#include "FieldInfo.h"

namespace Portal {

	template <size_t size>
	class BytesField : public Field<std::vector<byte> > {

		size_t nword;
		size_t nbyte;
		size_t offset;

	protected:

		void PrintValue(std::ostream& str) const;

	public:
		BytesField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~BytesField() {/* */};
	};

}


template<size_t size>
Portal::BytesField<size>::BytesField(const std::string& name, size_t nword, size_t nbyte) :
							Field<std::vector<byte> > (name,nword,nbyte*8,8*size),
							nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
	human.reserve(size);
	human.resize(size);
}

template<size_t size>
void Portal::BytesField<size>::Write(byte* raw_data) const {
	memset(raw_data + offset,0,size * sizeof(byte));
	for(size_t i = 0 ; i < size && i < human.size() ; i++)
		raw_data[offset + i] = human[i];
}

template<size_t size>
void Portal::BytesField<size>::Read(const byte* raw_data) {
	human.reserve(size);
	human.resize(size);
	for(size_t i = 0 ; i < size ; i++)
		 human[i] = raw_data[offset + i];
}

template<size_t size>
Portal::FieldInfo* Portal::BytesField<size>::Clone() const {
	BytesField<size>* new_ptr = new BytesField<size>(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

template<size_t size>
void Portal::BytesField<size>::PrintValue(std::ostream& str) const {
	for(size_t i = 0 ; i < size && i < human.size() ; i++)
		str << std::setw(2) << std::setfill('0') << std::hex << (unsigned int)human[i];
}

#endif /* BYTESFIELD_H_ */
