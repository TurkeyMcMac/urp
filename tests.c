#include "urp.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <string.h>

static void init(void)
{
	DDRB |= _BV(PB4) | _BV(PB5);
}

static void succeed(void)
{
	PORTB |= _BV(PB5);
	abort();
}

static void fail(void)
{
	PORTB |= _BV(PB4);
	abort();
}

#ifdef assert
#	undef assert
#endif
static void assert(int8_t cond)
{
	if (!cond) fail();
}

static void test_memmem(void)
{
	URPTR mem1 = URP_PGM(PSTR("12345"));
	URPTR mem2 = URP_RAM("11235");
	URPTR mem3 = URP_RAM("53421");
	URPTR mem4 = URP_PGM(PSTR("53211"));
	assert(urp_memmem(mem1, 0, mem3, 0) == mem1);
	assert(urp_memmem(mem1, 1, mem3, 0) == mem1);
	assert(urp_memmem(mem1, 1, mem2, 1) == mem1);
	assert(urp_memmem(mem1, 5, mem4, 1) == mem1 + 4);
	assert(urp_memmem(mem4, 5, mem2, 2) == mem4 + 3);
	assert(URP_IS_NULL(urp_memmem(mem2, 5, mem3, 3)));
	assert(URP_IS_NULL(urp_memmem(mem1, 2, mem4, 3)));
}

static void test_strcasecmp(void)
{
	URPTR str1 = URP_PGM(PSTR("abcdef"));
	URPTR str2 = URP_RAM("ABCDEF");
	URPTR str3 = URP_RAM("Abcdef");
	URPTR str4 = URP_PGM(PSTR("aBcDeF"));
	assert(urp_strcasecmp(str2, str3) == 0);
	assert(urp_strcasecmp(str1 + 1, str2) > 0);
	assert(urp_strcasecmp(str1 + 6, str4 + 6) == 0);
	assert(urp_strcasecmp(str2 + 6, str4) < 0);
	assert(urp_strcasecmp(str3, str4 + 2) < 0);
}

static void test_strcasestr(void)
{
	URPTR str1 = URP_PGM(PSTR("foobarbaz"));
	URPTR str2 = URP_RAM("foOBaRaz");
	URPTR str3 = URP_RAM("oba");
	URPTR str4 = URP_PGM(PSTR("rB"));
	assert(urp_strcasestr(str1, str3) == str1 + 2);
	assert(urp_strcasestr(str1, str4) == str1 + 5);
	assert(URP_IS_NULL(urp_strcasestr(str3, str1)));
	assert(urp_strcasestr(str2, str3) == str2 + 2);
	assert(URP_IS_NULL(urp_strcasestr(str1, str2)));
}

static void test_strcmp(void)
{
	URPTR str1 = URP_PGM(PSTR("abcdef"));
	URPTR str2 = URP_RAM("abcdef");
	assert(urp_strcmp(str2, str2) == 0);
	assert(urp_strcmp(str1 + 1, str2) > 0);
	assert(urp_strcmp(str1 + 6, str1 + 6) == 0);
	assert(urp_strcmp(str2 + 6, str1) < 0);
	assert(urp_strcmp(str2, str1 + 2) < 0);
}

static void test_strcspn(void)
{
	URPTR str1 = URP_PGM(PSTR("abcdef123"));
	URPTR str2 = URP_RAM("");
	URPTR str3 = URP_RAM("321");
	URPTR str4 = URP_PGM(PSTR("abc"));
	assert(urp_strcspn(str1, str3) == 6);
	assert(urp_strcspn(str1, str4) == 0);
	assert(urp_strcspn(str3, str4) == 3);
	assert(urp_strcspn(str2, str3) == 0);
	assert(urp_strcspn(str2, str2) == 0);
}

static void test_strncasecmp(void)
{
	URPTR str1 = URP_PGM(PSTR("abcdef"));
	URPTR str2 = URP_RAM("ABCDEF");
	URPTR str3 = URP_RAM("Abcdef");
	URPTR str4 = URP_PGM(PSTR("aBcDeF"));
	assert(urp_strncasecmp(str2, str3, 6) == 0);
	assert(urp_strncasecmp(str2, str3, 7) == 0);
	assert(urp_strncasecmp(str1 + 1, str2, 3) > 0);
	assert(urp_strncasecmp(str1 + 5, str4 + 5, 1) == 0);
	assert(urp_strncasecmp(str2 + 6, str4, 6) < 0);
	assert(urp_strncasecmp(str3, str4 + 2, 0) == 0);
}

static void test_strncmp(void)
{
	URPTR str1 = URP_PGM(PSTR("abcdef"));
	URPTR str2 = URP_RAM("Abcdef");
	assert(urp_strncmp(str2, str1, 6) < 0);
	assert(urp_strncmp(str1, str2, 7) > 0);
	assert(urp_strncmp(str1 + 1, str2, 3) > 0);
	assert(urp_strncmp(str1 + 5, str2 + 5, 1) == 0);
	assert(urp_strncmp(str2 + 6, str2, 6) < 0);
	assert(urp_strncmp(str1, str2 + 2, 0) == 0);
}

static void test_strpbrk(void)
{
	URPTR str1 = URP_PGM(PSTR("abc 123 _-+"));
	URPTR str2 = URP_RAM(".,.");
	URPTR str3 = URP_RAM("xyzzz98");
	URPTR str4 = URP_PGM(PSTR("hjio*__"));
	URPTR str5 = URP_PGM(PSTR(""));
	assert(urp_strpbrk(str4, str1) == str4 + 5);
	assert(URP_IS_NULL(urp_strpbrk(str2, str3)));
	assert(URP_IS_NULL(urp_strpbrk(str5, str5)));
	assert(URP_IS_NULL(urp_strpbrk(str1, str5)));
	assert(urp_strpbrk(str1, str4) == str1 + 8);
}

static void test_strspn(void)
{
	URPTR str1 = URP_PGM(PSTR("abcdef123"));
	URPTR str2 = URP_RAM("");
	URPTR str3 = URP_RAM("321");
	URPTR str4 = URP_PGM(PSTR("abc"));
	assert(urp_strspn(str1, str1) == 9);
	assert(urp_strspn(str1, str3) == 0);
	assert(urp_strspn(str1, str4) == 3);
	assert(urp_strspn(str3, str4) == 0);
	assert(urp_strspn(str2, str3) == 0);
	assert(urp_strspn(str2, str2) == 0);
}

static void test_strstr(void)
{
	URPTR str1 = URP_PGM(PSTR("foobarbaz"));
	URPTR str2 = URP_RAM("foobaraz");
	URPTR str3 = URP_RAM("oba");
	URPTR str4 = URP_PGM(PSTR("rb"));
	assert(urp_strcasestr(str1, str3) == str1 + 2);
	assert(urp_strcasestr(str1, str4) == str1 + 5);
	assert(URP_IS_NULL(urp_strcasestr(str3, str1)));
	assert(urp_strcasestr(str2, str3) == str2 + 2);
	assert(URP_IS_NULL(urp_strcasestr(str1, str2)));
}

int main(void)
{
	init();
	test_memmem();
	test_strcasecmp();
	test_strcasestr();
	test_strcmp();
	test_strcspn();
	test_strncasecmp();
	test_strncmp();
	test_strpbrk();
	test_strspn();
	test_strstr();
	succeed();
	return 0;
}
