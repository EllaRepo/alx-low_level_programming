#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Performs simple operations
 * @argc: number of command line arguments
 * @argv: string vector of command line arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int result;
	int (*func_p)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	func_p =  get_op_func(argv[2]);
	if (func_p == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if (atoi(argv[3]) == 0)
	{
		printf("Error\n");
		exit(99);
	}
	result = 0;
	result = func_p(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", result);

	return (0);
}
