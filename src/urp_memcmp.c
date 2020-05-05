#include "urp.h"

int urp_memcmp(URPTR a, URPTR b, size_t n)
{
	size_t i;
	for (i = 0; i < n; ++i) {
		uint8_t a_byte = urp_read_byte(a + i);
		uint8_t b_byte = urp_read_byte(b + i);
		if (a_byte != b_byte) return (int)a_byte - (int)b_byte;
	}
	return 0;
}
