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
	char *str1, *str2;

	str1 = s1;
	str2 = s2;

	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 == *str2)
			;
		else
			return ((int) (*str1 - *str2));
		str1++;
		str2++;
	}

	return (0);
}

