/**
 * _memcpy - Copies memory area
 * @dest: Point to memory area of destination
 * @src: Point to memory area of source
 * @n: Number of bytes of a memory area
 *
 * Return: Returns a pointer to 'dest'
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

