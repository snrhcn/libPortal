#ifndef IPRESOLVER_H_
#define IPRESOLVER_H_

#include <string>
#include <cstring>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

namespace Portal {

	/* Validate IPv4 address */
	bool validateIpv4Address(const std::string& ipAddress);

	/* Validate IPv6 address */
	bool validateIpv6Address(const std::string& ipAddress);

	/* Return IP from a host address */
	int GetAddress(const std::string &hostname, std::string &result, int ai_family);
	std::string GetIP(const std::string& hostname);
	std::string GetIPv6(const std::string& hostname);

	/* Return the hostname of associated to the IP address */
	std::string GetHostname(const std::string& ip_address);
}

#endif /* IPRESOLVER_H_ */
