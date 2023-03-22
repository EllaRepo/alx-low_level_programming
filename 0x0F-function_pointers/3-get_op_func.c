#include <stdlib.h>
#include "3-calc.h"

/**
 * get_op_func - selects the correct function to perform
 *               the operation asked by the user
 * @s: operator passed as argument to the program
 *
 * Return: a pointer to the function that corresponds to
 *         the operator given as a parameter
 */
int (*get_op_func(char *s))(int, int)
{
	int (*func_p)(int, int) = NULL;
	op_t *ops, *tmp;

	ops = malloc(sizeof(op_t) * 6);
	if (ops == NULL)
		return (NULL);

	ops[0].op = "+", ops[0].f = op_add;
	ops[1].op = "-", ops[1].f = op_sub;
	ops[2].op = "*", ops[2].f = op_mul;
	ops[3].op = "/", ops[3].f = op_div;
	ops[4].op = "%", ops[4].f = op_mod;
	ops[5].op = NULL, ops[5].f = NULL;

	tmp = ops;
	while (tmp->op)
	{
		if (*(tmp->op) == *s)
		{
			func_p = tmp->f;
			break;
		}
		tmp++;
	}
	free(ops);
	return (func_p);
}
