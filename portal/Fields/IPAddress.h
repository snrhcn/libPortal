#ifndef IPADDRESS_H_
#define IPADDRESS_H_

#include <iostream>
#include <ostream>
#include <string>
#include <arpa/inet.h>

#include "FieldInfo.h"

namespace Portal {

	class IPAddress : public Field<std::string> {

		size_t nword;
		size_t nbyte;
		size_t offset;
    	struct in_addr address;

		void PrintValue(std::ostream& str) const;

	public:

		IPAddress(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		void SetField(const std::string& ip_address);

        operator byte*() { return (byte*)&address.s_addr; }

		virtual ~IPAddress();

	};

}


#endif /* IPADDRESS_H_ */
