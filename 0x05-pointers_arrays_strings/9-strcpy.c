/**
 * _strcpy - Copies the string pointed by 'scr', including the terminating
 * null bye (\0, to the buffer pointed to by 'dest'
 * @src: A pointer to the src string
 * @dest: A pointer to the dest string
 *
 * Return: The pointer to 'dest'
 */
char *_strcpy(char *dest, char *src)
{
	char *s, *d;

	s = src;
	d = dest;
	while ((*d++ = *s++) != '\0')
		;
	return (dest);
}

