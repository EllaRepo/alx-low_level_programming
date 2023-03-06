#include <stdio.h>

/**
 * set_string - Sets the value of a pointer to a char
 * @s: Double pointer to char
 * @to: A pointer to char
 *
 * Return: None
 */
void set_string(char **s, char *to)
{
	*s = to;
}
