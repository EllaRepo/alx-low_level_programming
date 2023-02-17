#include <stdio.h>

/**
 * main - Prints the lowercase alphabet in reverse, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = 'z';

	while (c >= 'a')
		putchar (c--);
	putchar ('\n');
	return (0);
}
