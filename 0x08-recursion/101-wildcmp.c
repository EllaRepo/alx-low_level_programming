/**
 * is_unique - Checks the uniqueness of a character in a given string
 * @s: Point to a string
 * @c: A character
 *
 * Return: 1 if the character is unique
 *         0 otherwise
 */
int is_unique(char *s, char c)
{
	if (*s == '\0')
		return (1);
	if (*s == c)
		return (0);
	s++;
	return (is_unique(s, c));
}
/**
 * wildcmp - Compares two strings
 * @s1: Point to the first string
 * @s2: Point to the second string
 *
 * Return: 1 if the strings can be considered identical
 *         0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	char *tmp;

	if ((*s1 == '\0' && *s2 == '\0') ||
			(*s1 == '\0' && *s2 == 0x2A && *(s2 + 1) == '\0'))
		return (1);
	if ((*s2 == 0x2A && *(s2 + 1) == 0x2A))
	{
		s2++;
		return (wildcmp(s1, s2));
	}
	if (*s2 == 0x2A && *(s2 + 1) == *s1)
	{
		tmp = s1 + 1;
		if (is_unique(tmp, *s1))
		{
			s2++;
			return (wildcmp(s1, s2));
		}
		tmp = s2 + 2;
		if (!is_unique(tmp, *s1))
		{
			s2++;
			return (wildcmp(s1, s2));
		}

	}
	if (*s2 == '\0')
		return (0);
	if (*s1 == *s2)
	{
		s1++, s2++;
		return (wildcmp(s1, s2));
	}
	else if (*s2 != 0x2A && *s1 != *s2)
	{
		return (0);
	}
	s1++;
	return (wildcmp(s1, s2));
}
