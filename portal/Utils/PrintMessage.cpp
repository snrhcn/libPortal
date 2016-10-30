#include "PrintMessage.h"

using namespace std;
using namespace Portal;

namespace Portal {
	extern /* Verbose mode flag */
	byte ShowWarnings;
}

void Portal::PrintMessage(uint16_t code, const string& routine, const string& message) {
	string code_str;

	switch(code) {
		/* Just print some message */
		case PrintCodes::PrintMessage :
			code_str = "[@] MESSAGE ";
			break;

	    /* Print a warning */
		case PrintCodes::PrintWarning :
			code_str = "[!] WARNING ";
			break;

		/* Print a warning */
		case PrintCodes::PrintWarningPerror :
			code_str = "[!] WARNING ";
			break;

		/* Print the error message */
		case PrintCodes::PrintError :
			code_str = "[!] ERROR ";
			break;
		case PrintCodes::PrintPerror :
			code_str = "[!] ERROR ";
			break;

		default:
			code_str = "";
			break;

	}

	/* Print String */
	string ret_str = code_str + " : " + routine + " -> " + message;

	/* Check if we should use the perror routine */
	if (code == PrintCodes::PrintPerror) {
		perror(ret_str.c_str());
		return;
	} else if (code == PrintCodes::PrintWarningPerror) {
		if(ShowWarnings)
			perror(ret_str.c_str());
		return;
	}

	if(code == PrintCodes::PrintMessage) {
		cout << ret_str << endl;
		return;
	} else if (code == PrintCodes::PrintWarning) {
		if(ShowWarnings)
			cerr << ret_str << endl;
		return;
	} else {
		cerr << ret_str << endl;
		return;
	}
}

