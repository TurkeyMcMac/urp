#ifndef URP_H_
#define URP_H_

#include <stddef.h>
#include <stdint.h>

typedef int16_t URPTR;
/* The equivalent of a char* that can point to either RAM or program memory.
 *
 * Like a char*, a URPTR can be incremented and decremented by a number of
 * bytes, checked for equality to other URPTRs, and compared as less than or
 * greater than other URPTRs to the same object. Like a char*, overflow and
 * underflow are undefined.
 *
 * Unlike a char*, a URPTR must be checked for nullness using URP_IS_NULL(ptr).
 * Use URP_NULL in place of NULL with URPTRS. Of course, a URPTR cannot be
 * written to. URPTRS also must be specially constructed and dereferenced. See
 * below.
 *
 * Also note that a URPTR can only point to the lower 32KiB of either RAM or
 * program memory.
 */

/*
 * The following macros will only evaluate each of their arguments once.
 */

#define URP_RAM(ram) ((URPTR)(ram))
/* Construct a URPTR from a pointer to RAM.
 */

#define URP_PGM(pgm) ((URPTR)(pgm) | URP_PGM_MARKER_)
/* Construct a URPTR from a pointer to program memory.
 */

#define URP_NULL URP_RAM((void *)0)
/* A URPTR representing NULL.
 */

#define URP_IS_RAM(ptr) (((ptr) & URP_PGM_MARKER_) == 0)
/* Returns whether the pointer is a pointer to RAM. It always holds that
 * URP_IS_RAM(ptr) XOR URP_IS_PGM(ptr).
 */

#define URP_IS_PGM(ptr) (((ptr) & URP_PGM_MARKER_) != 0)
/* Returns whether the pointer is a pointer to program memory. It always holds
 * that URP_IS_RAM(ptr) XOR URP_IS_PGM(ptr).
 */

#define URP_IS_NULL(ptr) ((void *)((ptr) & ~URP_PGM_MARKER_) == (void *)0)
/* Returns whether the pointer is null and is not to be dereferenced.
 */

#define URP_RAM_ADDR(ptr) ((void *)(ptr))
/* Get the address as a void* of a pointer known to point to RAM.
 */

#define URP_PGM_ADDR(ptr) ((void *)((ptr) & ~URP_PGM_MARKER_))
/* Get the address as a void* of a pointer known to point to program memory.
 */

uint8_t urp_read_byte(URPTR ptr);
/* Dereference a pointer, reading one byte.
 */

uint16_t urp_read_word(URPTR ptr);
/* Dereference a pointer, reading one word.
 */

uint32_t urp_read_dword(URPTR ptr);
/* Dereference a pointer, reading one double word.
 */

void *urp_read_ptr(URPTR ptr);
/* Dereference a pointer, reading one pointer.
 */

float urp_read_float(URPTR ptr);
/* Dereference a pointer, reading one single-precision floating point number.
 */

/*
 * The following functions are based on the string functions provided by AVR
 * libc. The semantics match the standard library functions, except that
 * pointers which only need to be read have been converted to URPTRs. Most
 * simply delegate to the standard functions, but those that take two or more
 * URPTR parameters require a separate implementation. These functions are
 * marked NOT TRIVIAL and are slower than the others because they are generic.
 */

URPTR urp_memchr(URPTR ptr, int c, size_t n);

int urp_memcmp(URPTR a, URPTR b, size_t n);

void *urp_memccpy(void *dest, URPTR src, int c, size_t n);

void *urp_memcpy(void *dest, URPTR src, size_t n);

/* NOT TRIVIAL */
URPTR urp_memmem(URPTR h, size_t hl, URPTR n, size_t nl);

URPTR urp_memrchr(URPTR ptr, int c, size_t n);

void *urp_memmove(void *dest, URPTR src, size_t n);

char *urp_strcat(char *dest, URPTR src);

URPTR urp_strchr(URPTR str, int c);

URPTR urp_strchrnul(URPTR str, int c);

/* NOT TRIVIAL */
int urp_strcmp(URPTR a, URPTR b);

char *urp_strcpy(char *dest, URPTR src);

/* NOT TRIVIAL */
int urp_strcasecmp(URPTR a, URPTR b);

/* NOT TRIVIAL */
URPTR urp_strcasestr(URPTR inside, URPTR find);

/* NOT TRIVIAL */
size_t urp_strcspn(URPTR str, URPTR reject);

size_t urp_strlcat(char *dest, URPTR src, size_t n);

size_t urp_strlcpy(char *dest, URPTR src, size_t n);

size_t urp_strlen(URPTR str);

size_t urp_strnlen(URPTR str, size_t n);

/* NOT TRIVIAL */
int urp_strncmp(URPTR a, URPTR b, size_t n);

/* NOT TRIVIAL */
int urp_strncasecmp(URPTR a, URPTR b, size_t n);

char *urp_strncat(char *dest, URPTR src, size_t n);

char *urp_strncpy(char *dest, URPTR src, size_t n);

/* NOT TRIVIAL */
URPTR urp_strpbrk(URPTR str, URPTR accept);

URPTR urp_strrchr(URPTR str, int c);

char *urp_strsep(char **str, URPTR delim);

/* NOT TRIVIAL */
size_t urp_strspn(URPTR str, URPTR accept);

/* NOT TRIVIAL */
URPTR urp_strstr(URPTR h, URPTR n);

char *urp_strtok(char *str, URPTR delim);

char *urp_strtok_r(char *str, URPTR delim, char **last);

#define URP_PGM_MARKER_ ((URPTR)0x8000)
/* This is private. It's the bit indicating a pointer to program memory, and
 * must be cleared before dereferencing.
 */

#endif /* URP_H_ */
