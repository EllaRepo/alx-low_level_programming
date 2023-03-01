/**
 * _strcat - Concatenates two strings
 * @dest: A char pointer pointing to the destination string
 * @src: A char pointer pointing to the source string
 *
 * Return: A pointer to the resulting string 'dest'
 */
char *_strcat(char *dest, char *src)
{
	char *d, *s;

	d = dest;
	s = src;
	while (*d)
		d++;
	while ((*d++ = *s++) != '\0')
		;

	return (dest);
}

