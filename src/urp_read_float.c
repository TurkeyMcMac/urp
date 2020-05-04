#include "urp.h"
#include <avr/pgmspace.h>

float urp_read_float(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(float *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_float(URP_PGM_ADDR(ptr));
}
