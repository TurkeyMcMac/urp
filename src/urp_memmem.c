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
