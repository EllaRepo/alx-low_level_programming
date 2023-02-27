#include "main.h"

/**
 * print_rev - Prints a string, in reverse, followed by a new line
 * @s: A pointer pointing to a string
 *
 * Return: None.
 */
void print_rev(char *s)
{
	int len;
	char *str;

	len = 0;
	str = s;
	while (*str)
	{
		len++;
		str++;
	}
	str = s;
	len -= 1;
	while (len >= 0)
		_putchar(*(str + len--));
	_putchar('\n');
}

