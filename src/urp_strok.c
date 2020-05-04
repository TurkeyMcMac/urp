#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strok(char *str, URPTR delim)
{
	static char *last;
	return urp_strtok_r(str, delim, &last);
}
