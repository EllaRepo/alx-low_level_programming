/**
 * _strspn - Gets the length of a prefix substring
 * @s: Point to a string
 * @accept: A string to be consisted
 *
 * Return: The number of bytes in the initial segment of 's'
 *         which consist only of bytes from 'accept'
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, prefix;

	for (prefix = -1; *accept != '\0'; accept++)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == *accept)
			{
				prefix = i > prefix || prefix == -1 ?
					i : prefix;
				break;
			}
		}
	}
	return (prefix == -1 ? 0 : prefix + 1);
}
