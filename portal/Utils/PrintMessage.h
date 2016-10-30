#ifndef PRINTMESSAGE_H_
#define PRINTMESSAGE_H_

#include <iostream>
#include <string>
#include <cstdio>
#include <stdint.h>

#include "../Types.h"

namespace Portal {

	namespace PrintCodes {
		const uint16_t PrintMessage = 0;
		const uint16_t PrintWarning = 1;
		const uint16_t PrintError = 2;
		const uint16_t PrintPerror = 3;
		const uint16_t PrintWarningPerror = 4;
	}

	/* Return a string with a message from some routine o the library */
	void PrintMessage(uint16_t code, const std::string& routine, const std::string& message = "");
}


#endif /* PRINTMESSAGE_H_ */
