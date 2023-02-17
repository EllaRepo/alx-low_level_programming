#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints the last digit of a randomly generated  number
 *
 * Description: Assign a random number to the variable 'n' each time
 * it executed. Then program output the string "Last digit of"
 * followed by the value in 'n', followed by the string "is",
 * followed by the string
 * - "and is greater than 5" if the last digit of n is greater than 5
 * - "and is 0" if the last digit of n is 0
 * - "and is less than 6 and not 0" if the last digit of n is less
 *   ithan 6 and not 0
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n, last_digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_digit = n % 10;
	printf("Last digit of %d is %d and is ", n ,last_digit);
	if (last_digit > 5)
		printf("greater than 5\n");
	else if (last_digit == 0)
		printf("0\n");
	else
		printf("less than 6 and not 0\n");
	return (0);
}
