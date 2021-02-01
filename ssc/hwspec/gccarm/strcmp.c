int strcmp(const char *s1, const char *s2)
{
	char *p1 = s1;
	char *p2 = s2;
	int r = 0;

	/* undefined behaviour accrding to standard, but gracious fail */
	if (!p1) return -1;
	if (!p2) return 1;

	while (*p1 && *p2 && !r) {
		r += *p1 - *p2;
		p1++, p2++;
	}
	if (!r) r += *p1 - *p2;
	return r;
}
