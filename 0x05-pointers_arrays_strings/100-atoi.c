/**
 * _atoi - Converts a string to an integer
 * @s: A pointer to a string
 *
 * Return: Converted integer
 */
char _atoi(char *s)
{
	int n, sign, i;
	char *c;

	if (*s == '\0')
		return (0);
	i = 0;
	sign = 1;
	c = s;
	while (*c != '\0' && (*c < '0' || *c > '9'))
		c++;
	if (c[-1] == '-')
		sign = -1;
	for (n = 0; *c != '\0' && *c >= '0' && *c <= '9'; i++)
	{
		n = n * 10 + (*c - '0');
		c++;
	}

	return (n * sign);
}

