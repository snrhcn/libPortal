#include "IPLayer.h"
#include "IP.h"
#include "IPv6.h"
#include "../Utils/IPResolver.h"
#include "../Utils/PortalUtils.h"

using namespace std;
using namespace Portal;

/* Method to build IP layer from the source address */
IPLayer* Portal::IPLayer::BuildSrc(const std::string& ip_src) {
	IPLayer* ip_layer = 0;
	if(validateIpv4Address(ip_src)) ip_layer = new IP();
	if(validateIpv6Address(ip_src)) ip_layer = new IPv6();
	if(ip_layer) ip_layer->SetSourceIP(ip_src);
	return ip_layer;
}

/* Method to build IP layer from the destination address */
IPLayer* Portal::IPLayer::BuildDst(const std::string& ip_dst) {
	IPLayer* ip_layer = 0;
	if(validateIpv4Address(ip_dst)) ip_layer = new IP();
	if(validateIpv6Address(ip_dst)) ip_layer = new IPv6();
	if(ip_layer) ip_layer->SetDestinationIP(ip_dst);
	return ip_layer;
}

IPLayer* Portal::IPLayer::BuildDst(const std::string& ip_dst, const std::string& iface) {
	IPLayer* ip_layer = 0;
	string ip_src = "";
	if(validateIpv4Address(ip_dst)) {
		ip_layer = new IP();
		ip_src = GetMyIP(iface);
	}
	if(validateIpv6Address(ip_dst)) {
		ip_layer = new IPv6();
		ip_src = GetMyIPv6(iface);
	}
	if(ip_layer) {
		ip_layer->SetDestinationIP(ip_dst);
		ip_layer->SetSourceIP(ip_src);
	}
	return ip_layer;
}
