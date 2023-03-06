int _strcmp(char *s1, char *s2);

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
	int i;

	if (*haystack == '\0' || *needle == '\0')
		return (0);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == *needle)
		{
			if (_strcmp(haystack + i, needle) == 0)
				return (haystack + i);
		}
	}
	return (0);
}
/**
 * _strcmp - Compares two strings character by character
 * @s1: A string
 * @s2: A string
 *
 * Return: 0 if strings are equal
 *        >0 if the first non-matching character in s1 is greater (in ASCII)
 *           than that of s2
 *        <0 if the first non-matching character in s1 is less (in ASCII)
 *           than that of s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			;
		else
			return ((int) (s1[i] - s2[i]));
		i++;
	}
	return (0);
}
