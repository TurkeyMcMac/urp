#include "urp.h"
#include <ctype.h>

int urp_strncasecmp(URPTR a, URPTR b, size_t n)
{
	uint8_t a_byte, b_byte;
	for (;;) {
		if (!n--) return 0;
		a_byte = urp_read_byte(a++);
		b_byte = urp_read_byte(b++);
		if (a_byte != b_byte) {
			a_byte = tolower(a_byte);
			b_byte = tolower(b_byte);
			if (a_byte != b_byte) break;
		} else if (!a_byte)
			return 0;
	}
	return (int)a_byte - (int)b_byte;
}
