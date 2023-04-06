/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: integer
 * @m: integer
 *
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int tmp;

	tmp = n & ~m;

	while (tmp)
	{
		if ((tmp & 1) == 1)
			count++;
		tmp = tmp >> 1;
	}
	tmp = m & ~n;
	while (tmp)
	{
		if ((tmp & 1) == 1)
			count++;
		tmp = tmp >> 1;
	}
	return (count);
}

