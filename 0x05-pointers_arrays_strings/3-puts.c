#include "main.h"

/**
 * _puts - Prints a string, followed by a new line, to stdout
 * @str: A pointer pointing to a string
 *
 * Return: None.
 */
void _puts(char  *str)
{
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}

