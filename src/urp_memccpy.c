#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

void *urp_memccpy(void *dest, URPTR src, int c, size_t n)
{
	if(URP_IS_RAM(src))
		return memccpy(dest, URP_RAM_ADDR(src), c, n);
	else /* if (URP_IS_PGM(src)) */
		return memccpy_P(dest, URP_PGM_ADDR(src), c, n);
}
