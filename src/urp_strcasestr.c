#include "urp.h"

URPTR urp_strcasestr(URPTR h, URPTR n)
{
	size_t nl = urp_strlen(n);
	while (urp_read_byte(h)) {
		if (!urp_strncasecmp(h, n, nl)) return h;
		++h;
	}
	return URP_NULL;
}
