#include <stdio.h>
#include <stdlib.h>

/**
  * main - Prints the opcodes of its main function
  * @argc: number of command line argument
  * @argv: arrag of strings of command line argument
  *
  * Return: 0
  */
int main(int argc, char *argv[])
{
	char *opcode = (char *) main;
	int bytes, i;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}
	while (i < bytes)
	{
		printf("%02x ", opcode[i] & 0xFF);
		i++;
	}
	printf("\n");
	return (0);
}
