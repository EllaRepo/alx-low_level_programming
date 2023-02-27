/**
 * rev_string - Reverses a string
 * @s: A pointer pointing to a string
 *
 * Return: None.
 */
void rev_string(char *s)
{
	int j, i;
	char c, *str;

	j = 0;
	str = s;
	while (*str)
	{
		j++;
		str++;
	}
	str = s;
	j -= 1;
	i = 0;
	while (i < j)
	{
		c = *(str + i);
		*(s + i) = *(s + j);
		*(s + j) = c;
		i++;
		j--;
	}
}

