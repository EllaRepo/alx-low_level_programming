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
	for (i = 0; i < n && *s != '\0'; i++)
		*d++ = *s++;
	while (i < n)
	{
		*d++ = '\0';
		i++;
	}

	return (dest);
}

