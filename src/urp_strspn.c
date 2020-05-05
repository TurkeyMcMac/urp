#include "urp.h"

size_t urp_strspn(URPTR str, URPTR accept)
{
	uint8_t byte;
	size_t l = 0;
	while ((byte = urp_read_byte(str + l))
		&& !URP_IS_NULL(urp_strchr(accept, byte)))
	{
		++l;
	}
	return l;
}
