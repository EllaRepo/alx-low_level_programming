#include <stdio.h>

/**
 * main - Prints its program name, follwed by a new line
 * @argc: The number of command line arguments
 * @argv: An array of pointers pointing to the arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[argc - 1]);

	return (0);
}
