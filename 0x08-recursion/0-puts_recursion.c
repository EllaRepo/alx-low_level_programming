#include "main.h"

/**
 * _puts_recursion - Prints a string, followed by new line
 * @s:Point to a string
 *
 * Return: None
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s++);
	_puts_recursion(s);
}
