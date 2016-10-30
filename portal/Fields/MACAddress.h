#ifndef MACADDRESS_H_
#define MACADDRESS_H_

#include <iostream>
#include <ostream>
#include <string>
#include "FieldInfo.h"

namespace Portal {

	class MACAddress : public Field<std::string> {

		size_t nword;
		size_t nbyte;
		size_t offset;

		void PrintValue(std::ostream& str) const;

	public:

		MACAddress(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~MACAddress();
	};

}


#endif /* MACADDRESS_H_ */
