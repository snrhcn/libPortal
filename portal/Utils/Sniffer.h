#ifndef SNIFFER_H_
#define SNIFFER_H_

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <signal.h>
#include <pcap.h>

/* Define PCAP_NETMASK_UNKNOWN if not included on pcap.h */
#ifndef PCAP_NETMASK_UNKNOWN
        #define PCAP_NETMASK_UNKNOWN    0xffffffff
#endif

#include "../Portal.h"

namespace Portal {

	/* Data for each sniffer created */
	struct SnifferData {
		/* ID of the sniffer */
		word ID;
		/* Argument for the capture function */
		void* sniffer_arg;
		/* Type of the link layer */
		int link_type;
	};

	class Sniffer {

		/* String that defines the device we are listening */
		char* device;

		/* Filter */
		std::string filter;

		/* Sniffer ID, for global vector data */
		word ID;

		/* ID of the thread */
		pthread_t thread_id;

		/* Pointer for sniffer data on capture function */
		SnifferData* sniffer_data;

		/* -------------- Libpcap stuff ----------------- */

		/* Handle for the opened pcap session */
		pcap_t *handle;
		/* Type of link layer of the interface */
		int link_type;
		/* Pcap error messages buffer */
		char errbuf[PCAP_ERRBUF_SIZE];
		/* IP address of interface */
		bpf_u_int32 netp;
		/* Subnet mask of interface */
		bpf_u_int32 maskp;
		/* Compiled BPF filter */
		struct bpf_program fp;
		/* Flag if the thread was spawned */
		byte spawned;

		/* -------------- Static Members ---------------- */

		/* Mutex variable */
		static pthread_mutex_t mutex_compile;

		/* Class counter */
		static word counter;

		/* Manage static Mutex variable used for multithreading */
		static void InitMutex();
		static void DestroyMutex();

		/* ---------------- Functions ------------------- */

		/* This class shouldn't be copied */
		Sniffer(const Sniffer& copy);
		Sniffer& operator= (const Sniffer& other);

		/* Compile Filter */
		void CompileFilter();

	public:
		/* Initialize and clean */
		friend void InitPortal();
		friend void CleanPortal();

		/* Constructor */
		Sniffer(const std::string& filter = "", const std::string& iface = "", Packet::PacketHandler PacketHandlerFunction = 0);

		/* Set filter */
		void SetFilter(const std::string& filter);

		/* Set device interface */
		void SetInterface(const std::string& iface );

		/* Set Packet Handler function */
		void SetPacketHandler(Packet::PacketHandler PacketHandlerFunction);

		/* Start capturing packets */
		void Capture(uint32_t count = -1, void *user = 0);

		/* Spawn the sniffer and return immediately to the user */
		void Spawn(uint32_t count = -1, void *user = 0);

		/* Block until the spawned thread finish the work */
		void Join();

		/* Cancel a sniffer */
		void Cancel();

		/* Destructor */
		virtual ~Sniffer();
	};

	/* Data for spawning a sniffer */
	struct SpawnData {
		/* User argument */
		void* user;
		/* Packet count, for Capture argument */
		uint32_t count;
		/* Pointer to the sniffer */
		Sniffer* sniff_ptr;
	};

}

#endif /* SNIFFER_H_ */
