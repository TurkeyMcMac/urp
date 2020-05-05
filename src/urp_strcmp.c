#include "urp.h"

int urp_strcmp(URPTR a, URPTR b)
{
	uint8_t a_byte, b_byte;
	for (;;) {
		a_byte = urp_read_byte(a++);
		b_byte = urp_read_byte(b++);
		if (a_byte != b_byte) break;
		if (!a_byte) return 0;
	}
	return (int)a_byte - (int)b_byte;
}
