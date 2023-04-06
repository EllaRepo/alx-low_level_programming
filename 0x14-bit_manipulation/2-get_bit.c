/**
 * get_bit - returns the value of a bit at a given index
 * @n: integer
 * @index: the index
 *
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int  i;

	i = 0;
	while (n)
	{
		if (index == i)
			return (n & 1);
		n = n >> 1;
		i++;
	}
	return ((sizeof(n) * 8) < index ? -1 : 0);
}

