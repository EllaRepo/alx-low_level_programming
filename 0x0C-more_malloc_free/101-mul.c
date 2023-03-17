#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _print - Prints strings
 * @str: point to the string
 *
 * Return: None
 */
void _print(char *str)
{
	while (*str != '\0')
		_putchar(*str++);
}

/**
 * exit_prog - Terminates the program by printing 'Error'
 *             and with an exit code of '98'
 *
 * Return: None
 */
void exit_prog(void)
{
	_print("Error\n");
	exit(98);
}
/**
 * allocate_mem - Allocates a memory block with a given size
 * @size: The size of memory block
 *
 * Return: A pointer to the new memory block
 */
char *allocate_mem(int size)
{
	char *c = malloc(size);

	if (c == NULL)
	{
		free(c);
		exit_prog();
	}
	c[size - 1] = '\0';
	size -= 2;
	while (size >= 0)
		c[size--] = '0';
	return (c);
}
/**
 * is_valid_arg - Checks the validity of the arguments
 * @argc: The number of command line arguments
 * @argv: An array of pointers pointing to the arguments
 * @sz: Point to an integer
 *
 * Return: None.
 */
void is_valid_arg(int argc, char *argv[], int *sz)
{
	if (argc != 3 || argv[1][0] == '-' || argv[2][0] == '-' ||
			argv[1][0] == '\0' || argv[2][0] == '\0')
		exit_prog();
	for (*sz = 0; argv[1][*sz] != '\0'; (*sz)++)
	{
		if (argv[1][*sz] < '0' || argv[1][*sz] > '9')
			exit_prog();
	}
	for (*(sz + 1) = 0; argv[2][*(sz + 1)] != '\0'; *(sz + 1) += 1)
	{
		if (argv[2][*(sz + 1)] < '0' || argv[2][*(sz + 1)] > '9')
			exit_prog();
	}
}
/**
 * _print_rev_recursion - prints a string in reverse.
 * @s: string
 * Return: no return.
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
/**
 * mul - Multiplies two positive number
 * @res: pointing to the result
 * @argv: An array of pointers pointing to the arguments
 * @sz: Point to the sizes of the arguments
 *
 * Return: None
 */
void mul(char *res, char *argv[], int *sz)
{
	int sz1, sz2, i, j, prod, rem;

	 sz2 = *(sz + 1) - 1;
	for (j = 0; sz2 >= 0; sz2--, j++)
	{
		sz1 = *sz - 1, prod = rem = 0, i = j;
		while (sz1 >= 0)
		{
			prod = (argv[1][sz1] - '0') * (argv[2][sz2] - '0')
				+ rem + (res[i] - '0');
			res[i] = (prod % 10) + '0';
			rem = prod / 10;
			sz1--, i++;
		}
		while (rem)
		{
			prod = (res[i] - '0') + rem;
			res[i] = (prod % 10) + '0';
			rem = prod / 10;
			i++;
		}
	}
	if ((res[*sz + *(sz + 1) - 1]) == '0')
		res[*sz + *(sz + 1) - 1] = '\0';
}
/**
 * main - Multiplies two positive number and  prints the result
 * @argc: The number of command line arguments
 * @argv: An array of pointers pointing to the arguments
 *
 * Return: 0 if two arguments are received
 */
int main(int argc, char *argv[])
{
	int size[2] = {0, 0};
	char *result;

	is_valid_arg(argc, argv, &size[0]);
	if ((size[0] == 1 && argv[1][0] == '0') ||
			(size[1] == 1 && argv[2][0] == '0'))
	{
		_print("0");
	}
	else
	{
		result = allocate_mem(sizeof(char) * (size[0] + size[1] + 1));
		mul(result, argv, size);
		_print_rev_recursion(result);
	}
	_print("\n");

	return (0);
}
