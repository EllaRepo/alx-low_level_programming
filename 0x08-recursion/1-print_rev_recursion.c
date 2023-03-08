#include "main.h"

/**
 * rev_recursion - Prints a string in reverse
 * @s: Point to the string
 *
 * Return: None.
 */
void rev_recursion(char *s)
{
	if (*s == '\0')
		return;
	s++;
	rev_recursion(s);
	_putchar(*s--);
}

/**
 * _print_rev_recursion - Prints a string in reverse
 * @s: Point to the string
 *
 * Return: None.
 */
void _print_rev_recursion(char *s)
{
	rev_recursion(s);
	_putchar('\n');
}
