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
	int i, j, prefix;

	for (prefix = 0, i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; ; j++)
		{
			if (accept[j] == '\0')
				return (prefix);
			if (s[i] == accept[j])
			{
				prefix = i + 1;
				break;
			}
		}
	}
	return (prefix);
}
