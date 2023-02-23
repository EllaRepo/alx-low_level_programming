#include "main.h"

/**
 * _isupper - Checks for uppercase character
 * @c: Input character to be checked
 *
 * Return: 1 if 'c' is upper
 *         0 otherwise
 */
int _isupper(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	else
		return (0);
}

