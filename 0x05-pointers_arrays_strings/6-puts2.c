#include "main.h"

/**
 * puts2 - Prints every other character of a string, starting with
 * the first character, followed by a new line.
 * @str: A pointer pointing to a string
 *
 * Return: None.
 */
void puts2(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (i % 2 == 0)
			_putchar(*str);
		str++;
		i++;
	}
	_putchar('\n');
}

