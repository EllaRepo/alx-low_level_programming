#include "main.h"

/**
 * _islower - Checks for lowercase character
 * @c: Input character to be checked
 *
 * Return: 1 if the character is lowercase
 *         0 otherwise
 */
int _islower(int c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	else
		return (0);
}

