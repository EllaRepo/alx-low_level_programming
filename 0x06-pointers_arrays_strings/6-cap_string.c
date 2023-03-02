/**
 * cap_string - Capitalizes all words of string
 * @s: A string
 *
 * Return: The char pointer pointing to the resulting string
 */
char *cap_string(char *s)
{
	char *str;
	char separators[] = {' ', '\t', '\n', ',', ';', '.', '!', '?', '"',
		'(', ')', '{', '}', '\0'};
	int i;

	str = s;
	*str = (*str >= 'a' && *str <= 'z') ? *str - 32 : *str;
	while (*str != '\0')
	{
		for (i = 0; separators[i] != '\0'; i++)
		{
			if (separators[i] == *str)
			{
				if (*(str + 1) >= 'a' && *(str + 1) <= 'z')
				{
					*(str + 1) -= 32;
					break;
				}
			}
		}
		str++;
	}

	return (s);
}
