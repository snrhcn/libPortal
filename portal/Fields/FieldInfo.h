#ifndef FIELDINFO_H_
#define FIELDINFO_H_

#include <string>
#include <stdint.h>
#include <cstring>
#include <iostream>
#include <cassert>

#include "../Types.h"

namespace Portal {

	class FieldInfo {
		/* --- Name of the field */
		std::string name;

		/* --- Localization Information (where the field is "located" inside a generic header) */
		word nword;    /* In which word is the field */
		word bitpos;   /* Start bit position of the field inside the word */
		word length;   /* Length of the field in bits) */

		/* --- Flag if the field was set by the user */
		byte field_set;

		/* --- Virtual private functions */

		/* Clone the information of the field into a new pointer */
		virtual FieldInfo* Clone() const = 0;
	public:

		FieldInfo(const std::string& name, word nword, word bitpos, word length);

		/* Write into the buffer */
		virtual void Write(byte* raw_data) const = 0;

		/* Get data from the buffer */
		virtual void Read(const byte* raw_data) = 0;

		/* Ostream operator of the field */
		friend std::ostream& operator<<(std::ostream& str, FieldInfo const& data);

		/* Clone the information of the field into a new pointer */
		FieldInfo* CloneField() const;

		/* Set the internal data */
		void SetWord(word nword) {this->nword = nword;};
		void SetBit(word bitpos) {this->bitpos = bitpos;};
		void SetLength(word length) {this->length = length;};
		void SetName(const std::string& name) {this->name = name;};
		void FieldSet() {this->field_set = 1;};
		void ResetField() {this->field_set = 0;};

		/* Get the internal data */
		word GetWord() const {return this->nword;};
		word GetBit() const {return this->bitpos;};
		word GetLength() const {return this->length;};
		word GetEnd() const {return (this->bitpos + this->length - 1);};
		std::string GetName() const {return this->name;};
		byte IsFieldSet() const {return this->field_set;};

		void PrintDebug() const;

		virtual void PrintValue(std::ostream& str) const = 0;

		void Print(std::ostream& str) const {
			str << GetName() << " = ";
			PrintValue(str);
		}

		virtual ~FieldInfo() {};
	};

	template<class HumanClass>
	class Field : public FieldInfo {

	protected:

		/* Human (readable) class that represents the value of this field */
		HumanClass human;

	public:
		Field(const std::string& name, word nword, word bitpos, word length) : FieldInfo(name,nword,bitpos,length) {};

		/* Set the field */
		virtual void SetField(const HumanClass& human) {this->human = human;};

		/* Get the field */
		HumanClass GetField() const {return this->human;};

		virtual ~Field() {};
	};

}


#endif /* FIELDINFO_H_ */
