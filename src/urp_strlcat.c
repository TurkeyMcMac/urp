#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

size_t urp_strlcat(char *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return strlcat(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return strlcat_P(dest, URP_PGM_ADDR(src), n);
}
