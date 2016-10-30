#include "IPResolver.h"
#include "PrintMessage.h"

using namespace std;

/* Validate IPv4 address */
bool Portal::validateIpv4Address(const std::string& ipAddress) {
	struct in_addr addr;
	return inet_pton(AF_INET, ipAddress.c_str(), &addr);
}

/* Validate IPv6 address */
bool Portal::validateIpv6Address(const std::string& ipAddress) {
	struct in6_addr addr;
	return inet_pton(AF_INET6, ipAddress.c_str(), &addr);
}

int Portal::GetAddress(const string &hostname, string &result, int ai_family) {
	struct addrinfo hints, *rp;
	int err;
	/* Attempt to resolve the hostname */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = ai_family;
	err = getaddrinfo(hostname.c_str(), NULL, &hints, &rp);
	if (err)
		return err;
	/* Convert IP to textual, numeric form */
	char addr[NI_MAXHOST];
	getnameinfo(rp->ai_addr, rp->ai_addrlen, addr,
			sizeof(addr), NULL, 0, NI_NUMERICHOST);
	freeaddrinfo(rp);
	result = addr;
	return 0;
}

string Portal::GetIP(const string& hostname) {
    string r;
	if (GetAddress(hostname, r, AF_INET))
		PrintMessage(Portal::PrintCodes::PrintWarningPerror,
				     "GetIPv4()","Error while resolving "+ hostname);
	return r;
}

string Portal::GetIPv6(const string& hostname) {
    string r;
	if (GetAddress(hostname, r, AF_INET6))
		PrintMessage(Portal::PrintCodes::PrintWarningPerror,
				     "GetIPv6()","Error while resolving "+ hostname);
	return r;
}

std::string Portal::GetHostname(const std::string& ip_address) {
	struct addrinfo hints, *rp;
	int err;
	/* Get a sockaddr */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	err = getaddrinfo(ip_address.c_str(), NULL, &hints, &rp);
	if (err)
		return ip_address;
	/* Make the inverse lookup */
	char addr[NI_MAXHOST];
	if (getnameinfo(rp->ai_addr, rp->ai_addrlen, addr, sizeof(addr), NULL, 0, 0))
		return ip_address;
	freeaddrinfo(rp);
	return string(addr);
}
