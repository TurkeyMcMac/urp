#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strcat(char *dest, URPTR src)
{
	if(URP_IS_RAM(src))
		return strcat(dest, URP_RAM_ADDR(src));
	else /* if (URP_IS_PGM(src)) */
		return strcat_P(dest, URP_PGM_ADDR(src));
}
