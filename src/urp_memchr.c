#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

URPTR urp_memchr(URPTR ptr, int c, size_t n)
{
	if(URP_IS_RAM(ptr))
		return URP_RAM(memchr(URP_RAM_ADDR(ptr), c, n));
	else /* if (URP_IS_PGM(ptr)) */
		return URP_PGM(memchr_P(URP_PGM_ADDR(ptr), c, n));
}
