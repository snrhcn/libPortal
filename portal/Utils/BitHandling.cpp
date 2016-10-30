#include "BitHandling.h"

#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
using namespace Portal;

void Portal::PrintBits (word value) {

	size_t maxbit = sizeof(word) * 8 - 1;

	bool print_flag = false;

	for (int i = maxbit ; i >= 0 ; i--)
		if (value & (1 << i)) {
			cout << "1";
			print_flag = true;
		}
		else {
			if (print_flag)
			  cout << "0";
		}

	cout << endl;
}

word Portal::SetBit(word value, byte bit)
{
	return value | (1 << bit);
}

word Portal::ResetBit(word value, byte bit)
{
	return value & ( ~(1 << bit) );
}

word Portal::TestBit(word value, byte bit)
{
	return 1&&(value & (1 << bit));
}

word Portal::ShiftRight(word value, byte ntimes) {
	for (short_word i = 0 ; i < ntimes ; i++)
		value >>= 1;

	return value;
}

/* Shift bits to right ntimes */
word Portal::ShiftLeft(word value, byte ntimes) {
	for (short_word i = 0 ; i < ntimes ; i++)
		value <<= 1;

	return value;
}

word Portal::ClearRange(word value, byte ibit, byte ebit) {
	for (byte i = ibit; i <= ebit ; i++)
		value = ResetBit(value,i);

	return value;
}

word Portal::ClearComplementRange(word value, byte ibit, byte ebit) {
	for (byte i = 0; i < ibit ; i++)
		value = ResetBit(value,i);

	for (byte i = ebit + 1; i <= 31 ; i++)
		value = ResetBit(value,i);

	return value;
}

#ifndef htonll
uint64_t Portal::htonll(uint64_t value) {
	static const int num = 42;

	if (*reinterpret_cast<const char*>(&num) == num) {
		const uint32_t high_part = htonl(static_cast<uint32_t>(value >> 32));
		const uint32_t low_part = htonl(static_cast<uint32_t>(value));
		return (static_cast<uint64_t>(low_part) << 32) | high_part;
	}
	return value;
}
#endif

#ifndef ntohll
uint64_t Portal::ntohll(uint64_t value) {
	return htonll(value);
}
#endif
