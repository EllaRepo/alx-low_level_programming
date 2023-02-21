#include "main.h"

/**
 * main - Prints '_putchar' followed by a new line
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	char str[] = "_putchar\n";

	for (i = 0; i < 9; i++)
		_putchar(str[i]);
	return (0);
}
