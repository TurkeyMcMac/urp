#include "urp.h"
#include <avr/pgmspace.h>

uint16_t urp_read_word(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(uint16_t *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_word(URP_PGM_ADDR(ptr));
}
