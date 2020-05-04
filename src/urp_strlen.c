#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

size_t urp_strlen(URPTR str)
{
	if(URP_IS_RAM(str))
		return strlen(URP_RAM_ADDR(str));
	else /* if (URP_IS_PGM(str)) */
		return strlen_P(URP_PGM_ADDR(str));
}
