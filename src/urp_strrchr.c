#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

URPTR urp_strrchr(URPTR str, int c)
{
	if(URP_IS_RAM(str))
		return URP_RAM(strrchr(URP_RAM_ADDR(str), c));
	else /* if (URP_IS_PGM(str)) */
		return URP_PGM(strrchr_P(URP_PGM_ADDR(str), c));
}
