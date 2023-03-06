/**
 * _memset - Fills memory with a constant byte
 * @s: Point a memory area to be filled
 * @b: A constant byte that fills
 * @n: Number of bytes of a memory area
 *
 * Return: A pointer to the memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}

