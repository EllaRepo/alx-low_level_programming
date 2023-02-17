#include <stdio.h>

/**
 * main - Prints all possible different combination of two
 *        digits separated by ',' followed by a space
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 48;
	int j;

	while (i < 57)
	{
		for (j = i + 1; j < 58; j++)
		{
			putchar (i);
			putchar (j);
			if (i == 56)
				break;
			putchar (',');
			putchar (' ');
		}
		i++;
	}
		putchar ('\n');
	return (0);
}
