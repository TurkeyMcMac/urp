#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strtok_r(char *str, URPTR delim, char **last)
{
	if(URP_IS_RAM(delim))
		return strtok_r(str, URP_RAM_ADDR(delim), last);
	else /* if (URP_IS_PGM(delim)) */
		return strtok_rP(str, URP_PGM_ADDR(delim), last);
}
