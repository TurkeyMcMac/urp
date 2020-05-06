/* This is an auto-generated concatenation. */
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
#line 1 "src/urp_memcmp.c"
#include "urp.h"

int urp_memcmp(URPTR a, URPTR b, size_t n)
{
	size_t i;
	for (i = 0; i < n; ++i) {
		uint8_t a_byte = urp_read_byte(a + i);
		uint8_t b_byte = urp_read_byte(b + i);
		if (a_byte != b_byte) return (int)a_byte - (int)b_byte;
	}
	return 0;
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
#line 1 "src/urp_memmem.c"
#include "urp.h"

URPTR urp_memmem(URPTR h, size_t hl, URPTR n, size_t nl)
{
	size_t i;
	if (nl > hl) return URP_NULL;
	for (i = 0; i <= hl - nl; ++i) {
		URPTR h_cmp = h + i;
		if (!urp_memcmp(h_cmp, n, nl)) return h_cmp;
	}
	return URP_NULL;
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
#line 1 "src/urp_read_dword.c"
#include "urp.h"
#include <avr/pgmspace.h>

uint32_t urp_read_dword(URPTR ptr)
{
	if(URP_IS_RAM(ptr))
		return *(uint32_t *)URP_RAM_ADDR(ptr);
	else /* if (URP_IS_PGM(ptr)) */
		return pgm_read_dword(URP_PGM_ADDR(ptr));
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
#line 1 "src/urp_strcasecmp.c"
#include "urp.h"
#include <ctype.h>

int urp_strcasecmp(URPTR a, URPTR b)
{
	uint8_t a_byte, b_byte;
	for (;;) {
		a_byte = urp_read_byte(a++);
		b_byte = urp_read_byte(b++);
		if (a_byte != b_byte) {
			a_byte = tolower(a_byte);
			b_byte = tolower(b_byte);
			if (a_byte != b_byte) break;
		} else if (!a_byte)
			return 0;
	}
	return (int)a_byte - (int)b_byte;
}
#line 1 "src/urp_strcasestr.c"
#include "urp.h"

URPTR urp_strcasestr(URPTR h, URPTR n)
{
	size_t nl = urp_strlen(n);
	while (urp_read_byte(h)) {
		if (!urp_strncasecmp(h, n, nl)) return h;
		++h;
	}
	return URP_NULL;
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
#line 1 "src/urp_strcmp.c"
#include "urp.h"

int urp_strcmp(URPTR a, URPTR b)
{
	uint8_t a_byte, b_byte;
	for (;;) {
		a_byte = urp_read_byte(a++);
		b_byte = urp_read_byte(b++);
		if (a_byte != b_byte) break;
		if (!a_byte) return 0;
	}
	return (int)a_byte - (int)b_byte;
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
#line 1 "src/urp_strcspn.c"
#include "urp.h"

size_t urp_strcspn(URPTR str, URPTR reject)
{
	uint8_t byte;
	size_t l = 0;
	while ((byte = urp_read_byte(str + l))
		&& URP_IS_NULL(urp_strchr(reject, byte)))
	{
		++l;
	}
	return l;
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
#line 1 "src/urp_strncasecmp.c"
#include "urp.h"
#include <ctype.h>

int urp_strncasecmp(URPTR a, URPTR b, size_t n)
{
	uint8_t a_byte, b_byte;
	for (;;) {
		if (!n--) return 0;
		a_byte = urp_read_byte(a++);
		b_byte = urp_read_byte(b++);
		if (a_byte != b_byte) {
			a_byte = tolower(a_byte);
			b_byte = tolower(b_byte);
			if (a_byte != b_byte) break;
		} else if (!a_byte)
			return 0;
	}
	return (int)a_byte - (int)b_byte;
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
#line 1 "src/urp_strncmp.c"
#include "urp.h"

int urp_strncmp(URPTR a, URPTR b, size_t n)
{
	uint8_t a_byte, b_byte;
	for (;;) {
		if (!n--) return 0;
		a_byte = urp_read_byte(a++);
		b_byte = urp_read_byte(b++);
		if (a_byte != b_byte) break;
		if (!a_byte) return 0;
	}
	return (int)a_byte - (int)b_byte;
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
#line 1 "src/urp_strok.c"
#include "urp.h"
#include <avr/pgmspace.h>
#include <string.h>

char *urp_strok(char *str, URPTR delim)
{
	static char *last;
	return urp_strtok_r(str, delim, &last);
}
#line 1 "src/urp_strpbrk.c"
#include "urp.h"

URPTR urp_strpbrk(URPTR str, URPTR accept)
{
	uint8_t byte;
	while ((byte = urp_read_byte(str))) {
		if (!URP_IS_NULL(urp_strchr(accept, byte))) return str;
		++str;
	}
	return URP_NULL;
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
#line 1 "src/urp_strspn.c"
#include "urp.h"

size_t urp_strspn(URPTR str, URPTR accept)
{
	uint8_t byte;
	size_t l = 0;
	while ((byte = urp_read_byte(str + l))
		&& !URP_IS_NULL(urp_strchr(accept, byte)))
	{
		++l;
	}
	return l;
}
#line 1 "src/urp_strstr.c"
#include "urp.h"

URPTR urp_strstr(URPTR h, URPTR n)
{
	size_t nl = urp_strlen(n);
	while (urp_read_byte(h)) {
		if (!urp_strncmp(h, n, nl)) return h;
		++h;
	}
	return URP_NULL;
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
