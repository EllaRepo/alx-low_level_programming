/**
 * _strlen - Returnns the length of a string
 * @s: Pointer to a characher
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

