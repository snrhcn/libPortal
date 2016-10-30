#ifndef PortalUTILS_H_
#define PortalUTILS_H_

#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "PacketContainer.h"

namespace Portal {

	/* Get interface hardware address */
	std::string GetMyMAC(const std::string& iface = "");
	/* Get MAC using an ARP request */
	const std::string GetMAC(const std::string& IPAddress, const std::string& iface = "");

	/* Get interface IP address */
	std::string GetMyIP(const std::string& iface = "");
	std::string GetMyIPv6(const std::string& iface = "", bool ll = true);

	/* Initialize and clean */
	void InitPortal();
	void CleanPortal();

	/* Parse an IP in nmap style */
	std::vector<std::string>* ParseIP(const std::string& argv); /* DEPRECATED */
	std::vector<std::string> GetIPs(const std::string& argv);

	/* Parse an octect in nmap style */
	std::vector<int>* ParseNumbers(const std::string& argv); /* DEPRECATED */
	std::vector<int> GetNumbers(const std::string& argv);

	/* Put port on a string */
	std::string StrPort(short_word port_number);

	/* Convert a container of ip address strings into raw data in network byte order */
	std::vector<byte> IPtoRawData(const std::vector<std::string>& ips);

	/* Convert raw data in network byte order into a container of ip address strings */
	std::vector<std::string> RawDatatoIP(const std::vector<byte>& raw_data);

	/* Cast layers to protocols */
	template<class T>
	T* GetLayer(Layer* layer) {
		return dynamic_cast<T*>(layer);
	}

	/* --------------- Search layers by protocols -------------- */

	ARP* GetARP(const Packet& packet);
	Ethernet* GetEthernet(const Packet& packet);
	ICMP* GetICMP(const Packet& packet);
	IPLayer* GetIPLayer(const Packet& packet);
	IP* GetIP(const Packet& packet);
	IPv6* GetIPv6(const Packet& packet);
	TCP* GetTCP(const Packet& packet);
	UDP* GetUDP(const Packet& packet);

	RawLayer* GetRawLayer(const Packet& packet);

	/* Portal the layer */
	void PortalLayer(Layer* layer);

	/* ------------------- Some operators ---------------------- */
	const Packet operator/(const Layer& left, const Layer& right);
	const Packet operator/(const Layer& left, const Packet& right);
}

/* ARP stuff */
#include "ARPSpoofing.h"

/* The sniffer */
#include "Sniffer.h"

#endif /* PortalUTILS_H_ */
