int isseparator(char c);

/**
 * cap_string - Capitalizes all words of string
 * @s: A string
 *
 * Return: The char pointer pointing to the resulting string
 */
char *cap_string(char *s)
{
	char *str;

	str = s;

	while (*str != '\0')
	{
		if (isseparator(*str))
		{
			if (*(str + 1) >= 'a' && *(str + 1) <= 'z')
				*(str + 1) -= 32;
		}
		str++;
	}

	return (s);
}

/**
 * isseparator - Checks if a character is a separator
 * @c: The character
 *
 * Return: 1 if a character is a separator
 *         0 otherwise
 */
int isseparator(char c)
{
	char separators[] = {' ', '\t', '\n', ',', ';', '.', '!', '?', '"',
		'(', ')', '{', '}', '\0'};

	int i;

	for (i = 0; separators[i] != '\0'; i++)
	{
		if (separators[i] == c)
			return (1);
	}

	return (0);
}
