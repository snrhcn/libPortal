#ifndef RAWSOCKET_H_
#define RAWSOCKET_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef __APPLE__
#include <features.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#else
#define ETH_P_ALL 1
#endif

#include <cerrno>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

#include "../Types.h"

namespace Portal {

	class SocketSender {

		struct SocketCouple {
			word protocol;
			int socket;
		};

		/* Map of socket to each interface requested by the user (by protocol ID) */
		static std::map<std::string,std::vector<SocketCouple> > socket_table;

		/* Prevent construction of this object */
		SocketSender();
		SocketSender(SocketSender& cpy);

		/* Sockets in link layer */
		static int CreateLinkSocket(word protocol_to_sniff = ETH_P_ALL);
		static int BindLinkSocketToInterface(const char *device, int rawsock, word protocol = ETH_P_ALL);

		/* Raw sockets */
		static int CreateRawSocket(word protocol_to_sniff = IPPROTO_RAW);
		static int CreateRaw6Socket(word protocol_to_sniff = IPPROTO_RAW);
		static int BindRawSocketToInterface(const char *device, int rawsock);

		/* Write data on the wire */
		static int SendLinkSocket(int rawsock, byte *pkt, size_t pkt_len);
		static int SendRawSocket(int rawsock, struct sockaddr *din, size_t size_dst, byte *pkt, size_t pkt_len);

	public:

		/* Request a socket */
		static int RequestSocket(const std::string& iface, word proto_id);
		/* Write into a socket */
		static int SendSocket(int rawsock, word proto_id, byte *pkt, size_t pkt_len);

		~SocketSender();
	};
}

#endif /* RAWSOCKET_H_ */
