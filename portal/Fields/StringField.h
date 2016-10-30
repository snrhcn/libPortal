#ifndef STRINGFIELD_H_
#define STRINGFIELD_H_

#include <iostream>
#include <ostream>
#include <string>
#include "FieldInfo.h"

namespace Portal {

	template<size_t size>
	class StringField : public Field<std::string> {

		size_t nword;
		size_t nbyte;
		size_t offset;

		void PrintValue(std::ostream& str) const;

	public:

		StringField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~StringField() {/* */};
	};

}

template<size_t size>
Portal::StringField<size>::StringField(const std::string& name, size_t nword, size_t nbyte) :
							Field<std::string> (name,nword,nbyte*8,8*size),
							nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

template<size_t size>
void Portal::StringField<size>::Write(byte* raw_data) const {
	memset(raw_data + offset,0,size * sizeof(byte));
	for(size_t i = 0 ; i < size && i < human.size() ; i++)
		raw_data[offset + i] = human[i];
}

template<size_t size>
void Portal::StringField<size>::Read(const byte* raw_data) {
	human = std::string((const char*)(raw_data + offset),size);
}

template<size_t size>
Portal::FieldInfo* Portal::StringField<size>::Clone() const {
	StringField<size>* new_ptr = new StringField<size>(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

template<size_t size>
void Portal::StringField<size>::PrintValue(std::ostream& str) const {
	str << human;
}

#endif /* STRINGFIELD_H_ */
