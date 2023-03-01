/**
 * _strncpy - Copies a strings
 * @dest: A char pointer pointing to the destination string
 * @src: A char pointer pointing to the source string
 * @n: Number of bytes from src
 *
 * Return: A pointer to the resulting string 'dest'
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *d, *s;
	int i;

	d = dest;
	s = src;
	i = 0;
	while (((*d++ = *s++) != '\0') && i < n)
		i++;

	return (dest);
}

