#include "urp.h"

URPTR urp_strpbrk(URPTR str, URPTR accept)
{
	uint8_t byte;
	while ((byte = urp_read_byte(str))) {
		if (!URP_IS_NULL(urp_strchr(accept, byte))) return str;
		++str;
	}
	return URP_NULL;
}
