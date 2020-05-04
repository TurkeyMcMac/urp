#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

URPTR urp_memrchr(URPTR ptr, int c, size_t n)
{
	if(URP_IS_RAM(ptr))
		return URP_RAM(memrchr(URP_RAM_ADDR(ptr), c, n));
	else /* if (URP_IS_PGM(ptr)) */
		return URP_PGM(memrchr_P(URP_PGM_ADDR(ptr), c, n));
}
