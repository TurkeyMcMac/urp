/* This is an auto-generated concatenation. */
#line 1 "src/urp_read_dword.c"
#include "urp.h"
#include <string.h>

uint32_t urp_read_dword(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(uint32_t *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_dword(URP_PGM_ADDR(ptr));
}
#line 1 "src/urp_strcat.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strcat(char *dest, URPTR src)
{
	if(URP_IS_RAM(src))
		return strcat(dest, URP_RAM_ADDR(src));
	else /* if (URP_IS_PGM(src)) */
		return strcat_P(dest, URP_PGM_ADDR(src));
}
#line 1 "src/urp_strsep.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strsep(char **str, URPTR delim)
{
	if(URP_IS_RAM(delim))
		return strsep(str, URP_RAM_ADDR(delim));
	else /* if (URP_IS_PGM(delim)) */
		return strsep_P(str, URP_PGM_ADDR(delim));
}
#line 1 "src/urp_strncpy.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strncpy(char *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return strncpy(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return strncpy_P(dest, URP_PGM_ADDR(src), n);
}
#line 1 "src/urp_read_ptr.c"
#include "urp.h"
#include <avr/pgmspace.h>

void *urp_read_ptr(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(void **)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_ptr(URP_PGM_ADDR(ptr));
}
#line 1 "src/urp_read_float.c"
#include "urp.h"
#include <avr/pgmspace.h>

float urp_read_float(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(float *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_float(URP_PGM_ADDR(ptr));
}
#line 1 "src/urp_strok.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strok(char *str, URPTR delim)
{
	static char *last;
	return urp_strtok_r(str, delim, &last);
}
#line 1 "src/urp_strncat.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strncat(char *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return strncat(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return strncat_P(dest, URP_PGM_ADDR(src), n);
}
#line 1 "src/urp_strlcpy.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

size_t urp_strlcpy(char *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return strlcpy(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return strlcpy_P(dest, URP_PGM_ADDR(src), n);
}
#line 1 "src/urp_strlcat.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

size_t urp_strlcat(char *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return strlcat(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return strlcat_P(dest, URP_PGM_ADDR(src), n);
}
#line 1 "src/urp_strnlen.c"
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
#line 1 "src/urp_memchr.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

URPTR urp_memchr(URPTR ptr, int c, size_t n)
{
	if(URP_IS_RAM(ptr))
		return URP_RAM(memchr(URP_RAM_ADDR(ptr), c, n));
	else /* if (URP_IS_PGM(ptr)) */
		return URP_PGM(memchr_P(URP_PGM_ADDR(ptr), c, n));
}
#line 1 "src/urp_read_byte.c"
#include "urp.h"
#include <avr/pgmspace.h>

uint8_t urp_read_byte(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(uint8_t *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_byte(URP_PGM_ADDR(ptr));
}
#line 1 "src/urp_memmove.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

void *urp_memmove(void *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return memmove(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return memcpy_P(dest, URP_PGM_ADDR(src), n);
}
#line 1 "src/urp_strchr.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

URPTR urp_strchr(URPTR str, int c)
{
	if(URP_IS_RAM(str))
		return URP_RAM(strchr(URP_RAM_ADDR(str), c));
	else /* if (URP_IS_PGM(str)) */
		return URP_PGM(strchr_P(URP_PGM_ADDR(str), c));
}
#line 1 "src/urp_strtok_r.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strtok_r(char *str, URPTR delim, char **last)
{
	if(URP_IS_RAM(delim))
		return strtok_r(str, URP_RAM_ADDR(delim), last);
	else /* if (URP_IS_PGM(delim)) */
		return strtok_rP(str, URP_PGM_ADDR(delim), last);
}
#line 1 "src/urp_strcpy.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strcpy(char *dest, URPTR src)
{
	if(URP_IS_RAM(src))
		return strcpy(dest, URP_RAM_ADDR(src));
	else /* if (URP_IS_PGM(src)) */
		return strcpy_P(dest, URP_PGM_ADDR(src));
}
#line 1 "src/urp_memrchr.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

URPTR urp_memrchr(URPTR ptr, int c, size_t n)
{
	if(URP_IS_RAM(ptr))
		return URP_RAM(memrchr(URP_RAM_ADDR(ptr), c, n));
	else /* if (URP_IS_PGM(ptr)) */
		return URP_PGM(memrchr_P(URP_PGM_ADDR(ptr), c, n));
}
#line 1 "src/urp_memccpy.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

void *urp_memccpy(void *dest, URPTR src, int c, size_t n)
{
	if(URP_IS_RAM(src))
		return memccpy(dest, URP_RAM_ADDR(src), c, n);
	else /* if (URP_IS_PGM(src)) */
		return memccpy_P(dest, URP_PGM_ADDR(src), c, n);
}
#line 1 "src/urp_strlen.c"
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
#line 1 "src/urp_read_word.c"
#include "urp.h"
#include <avr/pgmspace.h>

uint16_t urp_read_word(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(uint16_t *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_word(URP_PGM_ADDR(ptr));
}
#line 1 "src/urp_strrchr.c"
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
#line 1 "src/urp_memcpy.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

void *urp_memcpy(void *dest, URPTR src, size_t n)
{
	if(URP_IS_RAM(src))
		return memcpy(dest, URP_RAM_ADDR(src), n);
	else /* if (URP_IS_PGM(src)) */
		return memcpy_P(dest, URP_PGM_ADDR(src), n);
}
#line 1 "src/urp_strchrnul.c"
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
