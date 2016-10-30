#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/nameser.h>
#include <resolv.h>

#include "DNS.h"

using namespace std;
using namespace Portal;

DNS::DNSQuery::DNSQuery(const string& qname) : qname(qname) {
	/* Check the size */
	if(qname.size() != 0) {
		/* Compress the name */
		size_t nbytes = Compress();
		/* Update the size of the raw data */
		size = 2 * sizeof(short_word) + nbytes;
	}
	SetType(DNS::TypeA);
	SetClass(DNS::ClassIN);
}

DNS::DNSQuery::DNSQuery(const DNSQuery& query) {
	memcpy(cqname, query.cqname, NS_MAXCDNAME);
	qtype = query.qtype;
	qclass = query.qclass;
	qname = query.qname;
	size = query.size;
}

void DNS::DNSQuery::SetClass(short_word _class) {
	qclass = _class;
}

void DNS::DNSQuery::SetType(short_word _type) {
	qtype = _type;
}

void DNS::DNSQuery::SetName(const string& _name) {
	qname = _name;
	/* Make the compression */
	size_t nbytes = Compress();
	/* Update the size of the raw data */
	size = 2 * sizeof(short_word) + nbytes;
}

string DNS::DNSQuery::GetName() const {
	return qname;
}

short_word DNS::DNSQuery::GetType() const {
	return qtype;
}

short_word DNS::DNSQuery::GetClass() const {
	return qclass;
}

size_t DNS::DNSQuery::GetSize() const {
	return size;
}

size_t DNS::DNSQuery::Compress() {
	/* Put data into the buffer */
	int nbytes = ns_name_compress(qname.c_str(),cqname,NS_MAXCDNAME,0,0);
	if(nbytes == -1)
		throw std::runtime_error("DNS::DNSQuery::Compress() : Error compressing the domain name provided");
	else
		return nbytes;

	return -1;
}

size_t DNS::DNSQuery::Write(byte* data_ptr) const {
	/* Write the query into the buffer, should correctly allocated */
	for(size_t i = 0 ; i < (size - 2 * sizeof(short_word)) ; i++) {
		data_ptr[i] = cqname[i];
	}

	data_ptr += (size - 2 * sizeof(short_word));
	/* Put type */
	ns_put16(qtype,data_ptr); data_ptr += sizeof(qtype);
	/* Put class */
	ns_put16(qclass,data_ptr); data_ptr += sizeof(qtype);

	return size;
}

void DNS::DNSQuery::Print(std::ostream &out) const {
	out << "  < Query" << " (" << dec << GetSize() << " bytes) " << ":: ";
	out << "QName = " <<  GetName() << " ; " ;
	out << "Type = 0x" <<  hex << (unsigned int)(GetType()) << " ; " ;
	out << "Class = 0x" <<  hex << (unsigned int)(GetClass()) << " " ;
	out << "> ";
}


