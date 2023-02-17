#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers
 *        separated by ',', followed by a space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = '0';

	while (c <= '9')
	{
		putchar (c);
		if (c == '9')
			break;
		putchar (',');
		putchar (' ');
		c++;
	}
	putchar ('\n');
	return (0);
}
