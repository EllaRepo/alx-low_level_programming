#include <stdio.h>

/**
 * print_buffer - Prints a buffer
 * @b: Points to a buffer
 * @size: The size of the buffer to be printed
 *
 * Return: None.
 */
void print_buffer(char *b, int size)
{
	int i, j, k;
	char *buff;
	char str[10] = "";

	buff = b;
	j = 0;
	for (i = 1; i <= size; i++, buff++)
	{
		if (i % 10 == 1)
			printf("%08x:", i - 1);
		if (i % 2)
			printf(" ");
		if (*buff > 31 && *buff != 127)
			str[j] = *buff;
		else
			str[j] = 0x2E;
		printf("%02x", *buff);
		if (j == 9)
		{
			printf(" %s\n", str);
			j = -1;
		}
		if (i == size)
		{
			i += 1;
			while (i % 10 != 1)
			{
				if (i % 2)
					printf(" ");
				printf("  ");
				i++;
			}
			printf(" ");
			for (k = 0; k <= j; k++)
				printf("%c", str[k]);
			printf("\n");
		}
		j++;
	}
}
