#include "urp.h"
#include <avr/pgmspace.h>

void *urp_read_ptr(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(void **)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_ptr(URP_PGM_ADDR(ptr));
}
