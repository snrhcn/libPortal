#include "IPv6Address.h"
#include "../Utils/IPResolver.h"

using namespace std;
using namespace Portal;

IPv6Address::IPv6Address(const std::string& name, size_t nword, size_t nbyte) :
					     Field<std::string> (name,nword,nbyte*8,48),
					     nword(nword), nbyte(nbyte), offset(nword * 4 + nbyte){
	human = "::";
}

void IPv6Address::SetField(const string& ip_address) {
	if(!validateIpv6Address(ip_address))
		human = GetIPv6(ip_address);
	else
		human = ip_address;
	inet_pton(AF_INET6, human.c_str(), &addr.s6_addr);
}


void IPv6Address::Write(byte* raw_data) const {
	memcpy(raw_data + offset, &addr.s6_addr, sizeof(addr.s6_addr));
}

void IPv6Address::Read(const byte* raw_data) {
	memcpy(&addr.s6_addr, raw_data + offset, sizeof(addr.s6_addr));
	char addressBuffer[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &addr.s6_addr, addressBuffer, INET6_ADDRSTRLEN);
    human = string(addressBuffer);
}

FieldInfo* IPv6Address::Clone() const {
	IPv6Address* new_ptr = new IPv6Address(GetName(),nword,nbyte);
	new_ptr->human = human;
	return new_ptr;
}

void IPv6Address::PrintValue(std::ostream& str) const {
	str << human;
}

IPv6Address::~IPv6Address() { /* */ }
