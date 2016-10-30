#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../Utils/IPResolver.h"

#include "IPAddress.h"

using namespace std;
using namespace Portal;

IPAddress::IPAddress(const std::string& name, size_t nword, size_t nbyte) :
					 Field<std::string> (name,nword,nbyte*8,8*sizeof(word)),
					 nword(nword), nbyte(nbyte), offset(nword * 4 +nbyte) {
	human = "0.0.0.0";
}

void IPAddress::SetField(const string& ip_address) {
	if(!validateIpv4Address(ip_address))
		human = GetIP(ip_address);
	else
		human = ip_address;
    inet_pton(AF_INET, human.c_str(), &address.s_addr);
}

void IPAddress::Write(byte* raw_data) const {
	memcpy(raw_data + offset, &address.s_addr, sizeof(address.s_addr));
}

void IPAddress::Read(const byte* raw_data) {
	memcpy(&address.s_addr, raw_data + offset, sizeof(address.s_addr));
    char str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &address.s_addr, str, INET_ADDRSTRLEN);
	human = string(str);
}

FieldInfo* IPAddress::Clone() const {
	IPAddress* new_ptr = new IPAddress(GetName(),nword,nbyte);
	new_ptr->SetField(human);
	return new_ptr;
}

void IPAddress::PrintValue(std::ostream& str) const {
	str << human;
}

IPAddress::~IPAddress() { /* */ }

