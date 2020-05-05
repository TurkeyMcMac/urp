#ifndef URP_H_
#define URP_H_

#include <stddef.h>
#include <stdint.h>

typedef int16_t URPTR;

#define URP_RAM(ram) ((URPTR)(ram))

#define URP_PGM(pgm) ((URPTR)(pgm) | URP_PGM_MARKER_)

#define URP_NULL URP_RAM((void *)0)

#define URP_IS_RAM(ptr) (((ptr) & URP_PGM_MARKER_) == 0)

#define URP_IS_PGM(ptr) (((ptr) & URP_PGM_MARKER_) != 0)

#define URP_IS_NULL(ptr) ((void *)((ptr) & ~URP_PGM_MARKER_) == (void *)0)

#define URP_RAM_ADDR(ptr) ((void *)(ptr))

#define URP_PGM_ADDR(ptr) ((void *)((ptr) & ~URP_PGM_MARKER_))

uint8_t urp_read_byte(URPTR ptr);

uint16_t urp_read_word(URPTR ptr);

uint32_t urp_read_dword(URPTR ptr);

void *urp_read_ptr(URPTR ptr);

float urp_read_float(URPTR ptr);

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

char *urp_strok(char *str, URPTR delim);

char *urp_strtok_r(char *str, URPTR delim, char **last);

#define URP_PGM_MARKER_ ((URPTR)0x8000)

#endif /* URP_H_ */
