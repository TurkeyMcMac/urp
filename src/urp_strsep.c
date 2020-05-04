#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strsep(char **str, URPTR delim)
{
	if(URP_IS_RAM(delim))
		return strsep(str, URP_RAM_ADDR(delim));
	else /* if (URP_IS_PGM(delim)) */
		return strsep_P(str, URP_PGM_ADDR(delim));
}
