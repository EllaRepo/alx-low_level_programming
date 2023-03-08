#include <stdio.h>
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
		return (0);
	if (*s == c)
	{
		s++;
		return (1 + is_unique(s, c));
	}
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
	char *tmp1, *tmp2;
	int c1, c2;

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
		tmp1 = s1 + 1, tmp2 = s2 + 2, c1 = c2 = 0;
		c1 = is_unique(tmp1, *s1), c2 = is_unique(tmp2, *s1);
		if (c1 == c2 || c1 == 0)
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
