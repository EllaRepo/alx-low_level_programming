/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: Point to a string
 * @accept: A string to be matched
 *
 * Return: A pointer to the byte in 's' that matches one of the bytes
 *         in 'accept'
 *         NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, prefix;

	for (prefix = -1; *accept != '\0'; accept++)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == *accept)
			{
				prefix = i < prefix || prefix == -1 ? i
					: prefix;
				break;
			}
		}
	}
	return (prefix == -1 ? 0 : (s + prefix));
}

