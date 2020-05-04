#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

size_t urp_strnlen(URPTR str, size_t n)
{
	if(URP_IS_RAM(str))
		return strnlen(URP_RAM_ADDR(str), n);
	else /* if (URP_IS_PGM(str)) */
		return strnlen_P(URP_PGM_ADDR(str), n);
}
