#ifndef __APPLE__
#include <netinet/ether.h>
#else
#include <netinet/if_ether.h>
#endif
#include <cstdio>
#include "MACAddress.h"
#include "config.h"

using namespace std;
using namespace Portal;

#ifndef HAVE_ETHER_ATON_R
#ifndef isdigit
#define isdigit(c)  (c >= '0' && c <= '9')
#endif
#ifndef islower
#define islower(c)  (c >=  'a' && c <= 'z')
#endif
#ifndef isspace
#define isspace(c)  (c ==  ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
#endif
#ifndef isupper
#define isupper(c)  (c >=  'A' && c <= 'Z')
#endif
#ifndef tolower
#define tolower(c)  (isupper(c) ? ( c - 'A' + 'a') : (c))
#endif
#ifndef toupper
#define toupper(c)  (islower(c) ? (c - 'a' + 'A') : (c))
#endif

/*
  ether_aton code from glibc, GPL'd.
 */
struct ether_addr *ether_aton_r(const char *asc, struct ether_addr *addr)
{
	size_t cnt;

	for (cnt = 0; cnt < 6; ++cnt) {
		unsigned int number;
		char ch;

		ch = tolower (*asc);
		asc++;
		if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f'))
			return NULL;
		number = isdigit (ch) ? (ch - '0') : (ch - 'a' + 10);

		ch = tolower (*asc);
		if ((cnt < 5 && ch != ':') || (cnt == 5 && ch != '\0' && !isspace (ch))) {
			++asc;
			if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f'))
				return NULL;
			number <<= 4;
			number += isdigit (ch) ? (ch - '0') : (ch - 'a' + 10);

			ch = *asc;
			if (cnt < 5 && ch != ':')
				return NULL;
		}

		/* Store result.  */
		addr->ether_addr_octet[cnt] = (unsigned char) number;

		/* Skip ':'.  */
		++asc;
	}
	return addr;
}
#endif

MACAddress::MACAddress(const std::string& name, size_t nword, size_t nbyte) :
					 Field<std::string> (name,nword,nbyte*8,48),
					 nword(nword), nbyte(nbyte) {
	offset = nword * 4 + nbyte;
}

void MACAddress::Write(byte* raw_data) const {
	struct ether_addr * ptr = (struct ether_addr *) (raw_data + offset);
	ether_aton_r(human.c_str(),ptr);
}

void MACAddress::Read(const byte* raw_data) {
	const struct ether_addr * ptr = (const struct ether_addr *) (raw_data + offset);
	char buf[19];
	  sprintf (buf, "%02x:%02x:%02x:%02x:%02x:%02x",
			  ptr->ether_addr_octet[0], ptr->ether_addr_octet[1],
			  ptr->ether_addr_octet[2], ptr->ether_addr_octet[3],
			  ptr->ether_addr_octet[4], ptr->ether_addr_octet[5]);
	buf[18] = 0;
	human = string(buf);
}

FieldInfo* MACAddress::Clone() const {
	MACAddress* new_ptr = new MACAddress(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void MACAddress::PrintValue(std::ostream& str) const {
	str << human;
}

MACAddress::~MACAddress() { /* */ }
