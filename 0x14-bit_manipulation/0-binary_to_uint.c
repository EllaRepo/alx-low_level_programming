/**
 * two_pow_n - calculates two the power of n
 * @n: power
 *
 * Return: the result
 */
unsigned int two_pow_n(int n)
{
	unsigned int res;

	if (n == 0)
		return (1);
	res = 1;
	while (n > 0)
	{
		res *= 2;
		n--;
	}
	return (res);
}
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return: the converted number
 *         0 if there is one or more chars in the string b that is not 0 or 1
 *         b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	const char *d;
	unsigned int dec;
	int  i, j;

	if (!b)
		return (0);
	d = b, i = 0;
	while (*d)
	{
		if (*d < '0' || *d > '1')
			return (0);
		d++;
		i++;
	}
	d--;
	dec = 0, j = 0;
	while (i > 0)
	{
		dec +=  ((*d) - '0') * two_pow_n(j);
		i--, d--, j++;
	}
	return (dec);
}

