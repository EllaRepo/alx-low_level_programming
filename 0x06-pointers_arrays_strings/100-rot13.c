/**
 * rot13 - Encodes a string using rot13
 * @s: A string to be encoded
 *
 * Return: The char pointer pointing to the resulting string
 */
char *rot13(char *s)
{
	char *str;
	char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
		'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z', '\0'};
	char enc[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
		'L', 'M', '\0'};
	int i;

	str = s;
	while (*str != '\0')
	{
		for (i = 0; alpha[i] != '\0'; i++)
		{
			if (*str == alpha[i])
			{
				*str = enc[i];
				break;
			}
		}
		str++;
	}

	return (s);
}

