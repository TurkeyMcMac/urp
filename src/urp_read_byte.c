#include "urp.h"
#include <avr/pgmspace.h>

uint8_t urp_read_byte(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(uint8_t *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_byte(URP_PGM_ADDR(ptr));
}
