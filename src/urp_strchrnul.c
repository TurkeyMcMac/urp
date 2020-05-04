#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

URPTR urp_strchrnul(URPTR str, int c)
{
	if(URP_IS_RAM(str))
		return URP_RAM(strchrnul(URP_RAM_ADDR(str), c));
	else /* if (URP_IS_PGM(str)) */
		return URP_PGM(strchrnul_P(URP_PGM_ADDR(str), c));
}
