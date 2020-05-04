#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

void *urp_memcpy(void *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return memcpy(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return memcpy_P(dest, URP_PGM_ADDR(src), n);
}
