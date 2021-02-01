#include <string.h>

void *memset(void *s, int c, size_t n)
{
	size_t i;
	char *ptr = s;

	for(i=0; i<n; i++, ptr++) {
		*ptr = c;
	}

	return s;
}
