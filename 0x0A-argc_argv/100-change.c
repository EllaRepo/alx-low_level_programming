#include <stdio.h>
#include <stdlib.h>

/**
  * get_change - calculates the minimum number of coins to make
  * @money: The money
  *
  * Return: The resulting change
  */
int get_change(int money)
{
	if (money == 0)
		return (0);
	if (money >= 25)
		return (1 + get_change(money - 25));
	if (money >= 10)
		return (1 + get_change(money - 10));
	if (money >= 5)
		return (1 + get_change(money - 5));
	if (money >= 2)
		return (1 + get_change(money - 2));
	return (1 + get_change(money - 1));
}

/**
 * main - Prints the minimum number of coins to make change for
 *        an amount of money
 * @argc: The number of command line arguments
 * @argv: An array of pointers pointing to the arguments
 *
 * Return: 0 if all arguments are valid
 *         1 if the number of arguments if different from 1
 */
int main(int argc, char *argv[])
{
	int cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents <= 0)
	{
		printf("0\n");
	}
	else
	{
		cents = get_change(cents);
		printf("%d\n", cents);
	}

	return (0);
}
