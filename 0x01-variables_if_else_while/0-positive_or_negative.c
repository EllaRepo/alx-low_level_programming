#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Generates a random number and checks wether it's posive/zero/negative
 *
 * Description: First generates a random number using rand and srand functions
 * then prints out the number followed by "is positive" if the number is
 * greater than 0, "is zero" if the number is 0 and "is negative" if the number
 * is less than 0.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n < 0)
		printf("%d is negative\n", n);
	else if (n == 0)
		printf("%d is zero\n", n);
	else
		printf("%d is positive\n", n);
	return (0);
}
