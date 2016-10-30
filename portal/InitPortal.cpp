#include "InitPortal.h"
#include "Portal.h"
#include "Utils/PortalUtils.h"

void Portal::InitPortal() {
	ICMPv6 icmpv6_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&icmpv6_dummy);

	NullLoopback nullloop_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&nullloop_dummy);

	IPOptionSSRR ipssrr_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ipssrr_dummy);

	IPOptionRR iprr_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&iprr_dummy);

	IPOptionLSRR iplsrr_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&iplsrr_dummy);

	IPOptionTraceroute iptrace_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&iptrace_dummy);

	IPOptionPad ippadopt_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ippadopt_dummy);

	IPOption ipopt_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ipopt_dummy);

	IP ip_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ip_dummy);

	IPv6 ipv6_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ipv6_dummy);

	IPv6FragmentationHeader ipv6_frag_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ipv6_frag_dummy);

    IPv6RoutingHeader ipv6_rtg_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ipv6_rtg_dummy);

    IPv6SegmentRoutingHeader ipv6_sr_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ipv6_sr_dummy);

    IPv6MobileRoutingHeader ipv6_mr_dummy;
    /* Register the protocol, this is executed only once */
    Protocol::AccessFactory()->Register(&ipv6_mr_dummy);

	UDP udp_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&udp_dummy);

	TCP tcp_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&tcp_dummy);

	TCPOption opt_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&opt_dummy);

	TCPOptionSACKPermitted optsackp_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optsackp_dummy);

	TCPOptionSACK optsack_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optsack_dummy);

	TCPOptionWindowScale optwscale_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optwscale_dummy);

	TCPOptionMaxSegSize optmss_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optmss_dummy);

	TCPOptionTimestamp optts_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optts_dummy);

	TCPOptionEDO optedo_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optedo_dummy);

	TCPOptionFastOpen tfo_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&tfo_dummy);

	TCPOptionMPTCP optmptcp_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optmptcp_dummy);

	TCPOptionMPTCPCapable optmpcapable_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optmpcapable_dummy);

	TCPOptionMPTCPJoin optmpjoin_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optmpjoin_dummy);

	TCPOptionPad optpad_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&optpad_dummy);

	ICMP icmp_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&icmp_dummy);

	ICMPExtension icmp_extension_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&icmp_extension_dummy);

	ICMPExtensionMPLS icmp_extension_mpls_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&icmp_extension_mpls_dummy);

	ICMPExtensionObject icmp_extension_object_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&icmp_extension_object_dummy);

	Ethernet ether_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&ether_dummy);

	Dot1Q dot1q_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&dot1q_dummy);

	SLL sll_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&sll_dummy);

	ARP arp_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&arp_dummy);

	RawLayer raw_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&raw_dummy);

	DNS dns_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&dns_dummy);

	DHCP dhcp_dummy;
	/* Register the protocol, this is executed only once */
	Protocol::AccessFactory()->Register(&dhcp_dummy);

	/* Initialize seed of RNG */
	srand(time(NULL));

	/* Put verbose mode as default */
	ShowWarnings = 1;

	/* Initialize Mutex variables */
	Packet::InitMutex();
	Sniffer::InitMutex();

}

void Portal::CleanPortal() {
        /* Destroy Mutex Varibles */
        Packet::DestroyMutex();
        Sniffer::DestroyMutex();
}



