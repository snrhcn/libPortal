#include "PacketContainer.h"

using namespace std;
using namespace Portal;

void Portal::OpenPcapDumper(int link_type, const string& filename, pcap_t*& pd, pcap_dumper_t*& pdumper) {
	/* Open pcap file */
    pd = pcap_open_dead(link_type, 65535 /* snaplen */);
    /* Create the output file. */
    pdumper = pcap_dump_open(pd, filename.c_str());
}

void Portal::ClosePcapDumper(pcap_t* pd, pcap_dumper_t* pdumper) {
    pcap_close(pd);
    pcap_dump_close(pdumper);
}

void Portal::DumperPcap(pcap_dumper_t* pdumper, struct pcap_pkthdr* header, const byte* raw_data) {
    pcap_dump(reinterpret_cast<u_char*>(pdumper), header, raw_data);
}

void Portal::OpenOffPcap(int* link_type, pcap_t*& handle, const string& filename, const string& filter) {
	/* PCAP error messages buffer */
	char errbuf[PCAP_ERRBUF_SIZE];
	errbuf[0] = 0;
	/* Compiled BPF filter */
	struct bpf_program fp;

	handle = pcap_open_offline(filename.c_str(), errbuf);

	if (handle == NULL)
	  /* There was an error */
		throw std::runtime_error("Portal::ReadPcap() : opening the file: " + string(errbuf));

	if (strlen (errbuf) > 0) {
		PrintMessage(Portal::PrintCodes::PrintWarning,
				     "Portal::ReadPcap()",
			         string(errbuf));
	  errbuf[0] = 0;    /* re-set error buffer */
	}

	/* Find out the datalink type of the connection */
	*link_type = pcap_datalink(handle);

	if(filter.size() > 0) {

		/* Compile the filter, so we can capture only stuff we are interested in */
		if (pcap_compile (handle, &fp, filter.c_str(), 0, 0) == -1) {
			cerr << "[!] Bad filter expression -> " << filter << endl;
			throw std::runtime_error("Portal::ReadPcap() : Compiling filter : " + string(pcap_geterr (handle)));
		}

		/* Set the filter for the device we have opened */
		if (pcap_setfilter (handle, &fp) == -1)
			throw std::runtime_error("Portal::ReadPcap() : Setting the filter: " + string(pcap_geterr (handle)) );

		pcap_freecode(&fp);
	}

}

void Portal::LoopPcap(pcap_t *handle, int cnt, pcap_handler callback, u_char *user) {
	int r;
	if ((r = pcap_loop (handle, cnt, callback, user)) < 0) {
	  if (r == -1)
		  /* Pcap error */
			throw std::runtime_error("Portal::LoopPcap() : Error in pcap_loop " + string(pcap_geterr (handle)));
	  /* Otherwise return should be -2, meaning pcap_breakloop has been called */
	}
}

void Portal::ClosePcap(pcap_t *handle) {
	pcap_close(handle);
}

struct ReadData {
	Packet::PacketHandler packet_handler;
	void* user_arg;
	int link_type;
};

/* Callback function to process a packet after read it */
static void process_packet (u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
	Packet sniff_packet;

	/* Argument for packet handling */
	ReadData* total_arg = reinterpret_cast<ReadData*>(user);

	/* Construct the packet */
	sniff_packet.PacketFromLinkLayer(packet,header->len,total_arg->link_type);

	/* Set packet time stamp */
	sniff_packet.SetTimestamp(header->ts);

	/* Grab the data */
	Packet::PacketHandler PacketHandlerFunction = total_arg->packet_handler;
	void* arg = total_arg->user_arg;

	/* Execute function */
	PacketHandlerFunction(&sniff_packet, arg);
}

void Portal::ReadPcap(const std::string& filename, Packet::PacketHandler PacketHandlerFunction, void* user, const std::string& filter) {
	/* Handle for the opened pcap session */
	pcap_t *handle;
	/* Type of link layer of the interface */
	int link_type;

	OpenOffPcap(&link_type,handle,filename,filter);

	/* Prepare the data */
	ReadData rd;
	rd.link_type = link_type;
	rd.packet_handler = PacketHandlerFunction;
	rd.user_arg = user;

	u_char* arg = reinterpret_cast<u_char*>(&rd);

	LoopPcap(handle,-1,process_packet,arg);

	ClosePcap(handle);
}

/* ---------------- Send an Receive functions (wrappers for backward compatibility) -------------- */

/* DEPRECATED functions */

/* Dump packet container on a pcap file */
void Portal::DumpPcap(const std::string& filename, PacketContainer* pck_container) {
	PrintMessage(Portal::PrintCodes::PrintWarning,
			     "Portal::DumpPcap()",
		         "Deprecated function, please consider to use newer functions with iterators as arguments.");
	DumpPcap(pck_container->begin(), pck_container->end(), filename);
}

/* Read a pcap file */
PacketContainer* Portal::ReadPcap(const std::string& filename, const std::string& filter) {
	PrintMessage(Portal::PrintCodes::PrintWarning,
			     "Portal::ReadPcap()",
		         "Deprecated function, please consider to use newer functions with iterators as arguments.");
	PacketContainer* pck_ptr = new PacketContainer;
	ReadPcap(pck_ptr,filename,filter);
	return pck_ptr;
}

/* Send and Receive a container of packet */
PacketContainer* Portal::SendRecv(PacketContainer* pck_container, const std::string& iface,
		                  int num_threads, double timeout, int retry) {
	PrintMessage(Portal::PrintCodes::PrintWarning,
			     "Portal::SendRecv()",
		         "Deprecated function, please consider to use newer functions with iterators as arguments.");
	PacketContainer* pck_ptr = new PacketContainer(pck_container->size());
	SendRecv(pck_container->begin(), pck_container->end(), pck_ptr->begin(), iface, timeout, retry, num_threads);
	return pck_ptr;
}

/* Send a container of packet - Multithreading */
void Portal::Send(PacketContainer* pck_container, const std::string& iface, int num_threads) {
	PrintMessage(Portal::PrintCodes::PrintWarning,
			     "Portal::Send()",
		         "Deprecated function, please consider to use newer functions with iterators as arguments.");
	Send(pck_container->begin(), pck_container->end(), iface, num_threads);
}
