#include "main.h"

/**
 * _print_binary - prints unsigned integer in binary form
 * @n: integer
 *
 * Return: NOne
 */
void _print_binary(unsigned long int n)
{
	if (!n)
		return;
	_print_binary(n >> 1);
	_putchar((((n & 1) == 1) ? '1' : '0'));
}
/**
 * print_binary - prints unsigned integer in binary format
 * @n: integer
 *
 * Return: none
 */
void print_binary(unsigned long int n)
{
	if (!n)
		_putchar('0');
	else
		_print_binary(n);
}
