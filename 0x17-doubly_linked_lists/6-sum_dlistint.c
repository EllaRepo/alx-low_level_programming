#include <stdio.h>
#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a
 *                dlistint_t linked list
 * @head: pointer to dlistint_t
 *
 * Return: the sum
 */
int sum_dlistint(dlistint_t *head)
{
	if (!head)
		return (0);
	return (head->n + sum_dlistint(head->next));
}
