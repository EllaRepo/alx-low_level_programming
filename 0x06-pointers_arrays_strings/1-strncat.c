/**
 * _strcat - Concatenates two strings
 * @dest: A char pointer pointing to the destination string
 * @src: A char pointer pointing to the source string
 * @n: Number of bytes from src
 *
 * Return: A pointer to the resulting string 'dest'
 */
char *_strncat(char *dest, char *src, int n)
{
	char *d, *s;
	int i;

	d = dest;
	s = src;
	while (*d)
		d++;
	i = 0;
	while (i < n && (*d++ = *s++) != '\0')
		i++;
	*d = '\0';

	return (dest);
}

