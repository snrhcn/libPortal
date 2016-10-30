#include "ARP.h"

using namespace Portal;
using namespace std;

void ARP::ReDefineActiveFields() {
}

void ARP::Portal() {
}

string ARP::MatchFilter() const {
	/* Get IP Address of sender */
	string target_ip = GetTargetIP();
	word ip_number = ntohl(inet_addr(target_ip.c_str()));
	char str_ip_number[11];
	sprintf(str_ip_number,"%u",ip_number);
	str_ip_number[10] = 0;
	if (GetOperation() == ARP::Request) {
		string str = string(str_ip_number);
		return "(arp[7]=2 and arp[14:4] == " + str + ")";
	} else {
		return " ";
	}
}
