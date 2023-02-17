#include <stdio.h>

/**
 * main - Prints all the numbers of base 16 in lowercase,
 *        followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int c = 48;

	while (c <= 63)
	{
		if (c > 57)
			putchar (c + 39);
		else
			putchar (c);
		c++;
	}
	putchar ('\n');
	return (0);
}
