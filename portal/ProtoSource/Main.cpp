#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "Proto.h"

using namespace std;

static void CheckKey(const string& in, const string& exp, size_t line) {
	if(in != exp) {
		cerr << "[@] Unrecognized protocol parameter on line " << line << " : " << in << endl;
		exit(1);
	}
}

int main(int argc, char* argv[]) {

	if(argc < 2) {
		/* Print usage */
		cout << "[@] Usage: " << string(argv[0]) << " [file] " << endl;
		return 1;
	}

	/* File */
	ifstream file(argv[1]);

	/* Auxiliary variables */
	string line;
	string dummy;

	/* Line counter */
	size_t nline = 1;

	/* Name of the protocol */
	string protoName;
	/* ID of the protocol */
	string protoID;

	if (file.is_open()) {

		/* --- Get name */
		file >> dummy;
		CheckKey(dummy,"name",nline);
		file >> protoName;
		nline++;

		/* --- Get protocol */
		file >> dummy;
		CheckKey(dummy,"protoid",nline);
		file >> protoID;
		nline++;

	} else {
		cerr << "[@] Unable to open the file: " << argv[1] << endl;
		return 1;
	}

	/* Create protocol */
	Proto protocol(protoName,protoID);

	cout << "[@] Protocol name = " << protoName << endl;
	cout << "[@] Protocol ID = " << protoID << endl;

	/* Protocol size */
	size_t protocol_size = 0;

	/* Read until end of file */
	while ( file.good() ) {
		/* Get the type of field */
		string type;
		file >> type;

		/* Check for last line */
		if(type.size() == 0) break;

		/* Get the name of the field */
		string name;
		file >> name;

		/* Create this field from the factory */
		FieldType* ptr = FieldFactory::AccessFactory()->GetFieldByName(type,name);
		if(!ptr) {
			cerr << "[@] No field type " << type << " on line " << nline << endl;
			cerr << "[@] Parsed fields: " << endl;
			protocol.PrintDefinition(cout);
			return 1;
		}

		/* Read the data of this field */
		ptr->ReadData(file);
		protocol_size += ptr->Size();

		/* Push the field on the protocol */
		protocol.push_back(ptr);

		nline++;
	}

	/* Sanity checks */
	if (protocol_size%8 != 0)
		cout << "[#] WARNING: The header size don't have and integer number of bytes. " << endl;

	cout << "[@] Protocol size (bits) = " << protocol_size << endl;
	cout << "[@] Protocol size (bytes) = " << protocol_size/8 << endl;

	/* Set the size of the protocol */
	protocol.SetProtoSize(protocol_size/8);

	protocol.PrintHdr();
	protocol.PrintCpp();

	file.close();

	return 0;
}


