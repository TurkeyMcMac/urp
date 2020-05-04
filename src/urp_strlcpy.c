#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

size_t urp_strlcpy(char *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return strlcpy(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return strlcpy_P(dest, URP_PGM_ADDR(src), n);
}
