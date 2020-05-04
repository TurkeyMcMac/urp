#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strncpy(char *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return strncpy(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return strncpy_P(dest, URP_PGM_ADDR(src), n);
}
