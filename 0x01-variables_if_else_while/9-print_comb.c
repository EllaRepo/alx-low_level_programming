#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers
 *        separated by ',', followed by a space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int c = 48;

	while (c <= 57)
	{
		putchar (c);
		if (c == 57)
			break;
		putchar (',');
		putchar (' ');
		c++;
	}
	putchar ('\n');
	return (0);
}
