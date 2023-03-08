/**
 * _strlen_recursion - Returns the length of a string
 * @s: Point to the string
 *
 * Return: Length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s++ == '\0')
		return (0);
	return (1 + _strlen_recursion(s));
}
