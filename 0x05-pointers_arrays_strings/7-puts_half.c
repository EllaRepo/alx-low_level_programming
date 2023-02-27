#include "main.h"

/**
 * puts_half - Prints the second half of a string, followed by a new line.
 * @str: A pointer pointing to a string
 *
 * Return: None.
 */
void puts_half(char *str)
{
	int i;
	char *sp;

	i = 0;
	sp = str;
	while (*sp)
	{
		i++;
		sp++;
	}
	if (i % 2 == 0)
		i /= 2;
	else
		i = (i + 1) / 2;
	sp = str + i;
	while (*sp)
	{
		_putchar(*sp++);
	}
	_putchar('\n');
}

