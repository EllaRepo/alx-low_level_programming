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
	long n, chksum;
	char c;

	chksum = 0xad4;
	srand(time(0));
	while (chksum - n > 127)
	{
		c = rand() % 128;
		printf("%c", c);
		n += c;
	}
	c = chksum - n;
	printf("%c", c);
	printf("\n");

	return (0);
}

