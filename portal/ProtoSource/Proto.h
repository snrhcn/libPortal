#ifndef PROTO_H_
#define PROTO_H_

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "FieldType.h"

class Proto : public std::vector<FieldType*> {

	/* Protocol data */
	std::string protoName;

	/* Protocol ID */
	std::string protoID;

	/* Protocol Size */
	size_t protoSize;

	Proto(const Proto& p) { /* */ };

	/* Print license header */
	int PrintLicense(std::ostream& out, const std::string& name) const;

	/* Print the source file */
	void PrintConstructorCpp(std::ostream& out) const;
	void PrintPortalCpp(std::ostream& out) const;

public:
	Proto(const std::string& name, const std::string& id);

	/* Print the header */
	void PrintHdr() const;

	/* Print the source file */
	void PrintCpp() const;

	/* Print parsed fields definition */
	void PrintDefinition(std::ostream& out) const;

	void SetProtoName(const std::string& name) { protoName = name; };
	void SetProtoID(short_word id) { protoID = id; };
	void SetProtoSize(size_t size) { protoSize = size; };

	std::string GetProtoName() const { return protoName; };
	std::string GetProtoID() const { return protoID; };
	size_t GetProtoSize() const { return protoSize; };

	virtual ~Proto();
};

struct convert {
   void operator()(char& c) { c = toupper((unsigned char)c); }
};

std::string toUpper(std::string uperName);

#endif /* PROTO_H_ */
