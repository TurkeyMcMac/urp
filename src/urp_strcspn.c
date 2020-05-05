#include "urp.h"

size_t urp_strcspn(URPTR str, URPTR reject)
{
	uint8_t byte;
	size_t l = 0;
	while ((byte = urp_read_byte(str + l))
		&& URP_IS_NULL(urp_strchr(reject, byte)))
	{
		++l;
	}
	return l;
}
