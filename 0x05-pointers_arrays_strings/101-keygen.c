#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates random valid passwords for the program '101-crackme'
 *
 * Return: Always 0
 */
int main(void)
{
	int n, chksum;
	char c;

	chksum = 0xad4;
	srand(time(0));
	n = 0;
	while (chksum - n > 127)
	{
		c = rand() % 128;
		if ( c == 0)
			continue;
		printf("%c", c);
		n += c;
	}
	if (chksum - n)
		printf("%c", chksum - n);
	printf("\n");

	return (0);
}

