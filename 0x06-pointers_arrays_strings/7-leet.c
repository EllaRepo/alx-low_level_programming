/**
 * leet - Encodes a string into 1337
 * @s: A string to be encoded
 *
 * Return: The char pointer pointing to the resulting string
 */
char *leet(char *s)
{
	char *str;
	char enc[] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L', '\0'};
	char encvalue[] = {'4', '3', '0', '7', '1', '\0'};
	int i;

	str = s;

	while (*str != '\0')
	{
		for (i = 0; enc[i] != '\0'; i++)
		{
			if (*str == enc[i])
				*str = encvalue[i % 5];
		}
		str++;
	}

	return (s);
}

