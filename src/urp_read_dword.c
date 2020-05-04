#include "urp.h"
#include <string.h>

uint32_t urp_read_dword(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(uint32_t *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_dword(URP_PGM_ADDR(ptr));
}
