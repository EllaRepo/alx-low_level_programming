/**
 * string_toupper - Changes all lowercase letters of a string to uppercase
 * @s: A string
 *
 * Return: The char pointer pointing to the resulting string
 */
char *string_toupper(char *s)
{
	char *str;

	str = s;

	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}

	return (s);
}

