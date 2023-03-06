/**
 * _strchr - Locates a character in a string
 * @s: Point to a string
 * @c: A character to be pointed
 *
 * Return: A pointer to the first occurrence of the character 'c'
 *         NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (0);
}

