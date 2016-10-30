#ifndef IPV6ADDRESS_H_
#define IPV6ADDRESS_H_

#include <iostream>
#include <ostream>
#include <string>
#include "FieldInfo.h"
#include <arpa/inet.h>
#include <netinet/in.h>

namespace Portal {

	class IPv6Address : public Field<std::string> {

		size_t nword;
		size_t nbyte;
		size_t offset;
        struct in6_addr addr;

		void PrintValue(std::ostream& str) const;

	public:

		IPv6Address(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		void SetField(const std::string& ip_address);

		FieldInfo* Clone() const;

        operator byte*() {return (byte*)&addr.s6_addr;}

		virtual ~IPv6Address();
	};

}

#endif /* IPV6ADDRESS_H_ */
