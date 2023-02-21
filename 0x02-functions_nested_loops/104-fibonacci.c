#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers,
 *        starting with '1' and '2', followed by a new line
 *
 * Return: Always 0.
 */
int main(void)
{
	int i, chk1, chk2;
	long int prev1, prev2, curnt1, curnt2, tmp1, tmp2;

	prev1 = 1;
	curnt1 = 2;
	chk1 = chk2 = 1;
	printf("%ld, %ld", prev1, curnt1);
	for (i = 0; i < 96; i++)
	{
		if (chk1)
		{
			tmp1 = prev1 + curnt1;
			printf(", %ld", tmp1);
			prev1 = curnt1;
			curnt1 = tmp1;
		}
		else
		{
			if (chk2)
			{
				prev2 = prev1 % 1000000000;
				curnt2 = curnt1 % 1000000000;
				prev1 /= 1000000000;
				curnt1 /= 1000000000;
				chk2 = 0;
			}
			tmp2 = prev2 + curnt2;
			tmp1 = prev1 + curnt1 + (tmp2 / 1000000000);
			printf(", %ld", tmp1);
			printf("%ld", tmp2 % 1000000000);
			prev1 = curnt1;
			prev2 = curnt2;
			curnt1 = tmp1;
			curnt2 = tmp2 % 1000000000;
		}
		if ((prev1 + curnt1 < 0) && chk1 == 1)
			chk1 = 0;
	}
	printf("\n");
	return (0);
}
