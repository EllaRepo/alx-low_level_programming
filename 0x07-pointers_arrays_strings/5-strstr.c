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

	if (*needle == '\0')
		return (haystack);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == *needle)
		{
			j = 1;
			while (1)
			{
				if (needle[j] == '\0')
					return (haystack + i);
				if (haystack[i + j] != needle[j])
					break;
				j++;
			}
		}
	}
	return (0);
}
