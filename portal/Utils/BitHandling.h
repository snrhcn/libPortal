#ifndef BITHANDLING_H_
#define BITHANDLING_H_

#include <iostream>
#include <string>
#include <cstdio>
#include <stdint.h>

typedef uint32_t word;
typedef uint16_t short_word;
typedef uint8_t byte;

/* Functions for manipulating bits on a word */

namespace Portal {

	/* Print to STDOUT the bits on word */
	void PrintBits (word value);

	/* Set a bit */
	word SetBit(word value, byte bit);

	/* Reset a bit */
	word ResetBit(word value, byte bit);

	/* Test a bit */
	word TestBit(word value, byte bit);

	/* Shift bits to right ntimes */
	word ShiftRight(word value, byte ntimes);

	/* Shift bits to right ntimes */
	word ShiftLeft(word value, byte ntimes);

	/* Clear range of bits (including ebit) */
	word ClearRange(word value, byte ibit, byte ebit);

	/* Clear all bits except the range specified */
	word ClearComplementRange(word value, byte ibit, byte ebit);

#ifndef htonll
	uint64_t htonll(uint64_t value);
#endif

#ifndef ntohll
	uint64_t ntohll(uint64_t value);
#endif

}

#endif /* BITHANDLING_H_ */
