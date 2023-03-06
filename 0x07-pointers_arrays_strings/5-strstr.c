/**
 * _strstr - Locates a substring
 * @haystack: Point to a string from which substring will be located
 * @needle: A substring to be located
 *
 * Return: A pointer to the beginning of the located substring
 *         NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (*haystack == '\0' || *needle == '\0')
		return (0);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == *needle)
		{
			for (j = 1; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			return (haystack + i);
		}
	}
	return (0);
}
