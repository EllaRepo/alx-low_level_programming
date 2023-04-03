#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer to listint_t
 *
 * Return: the sum
 */
int sum_listint(listint_t *head)
{
	if (!head)
		return (0);
	return (head->n + sum_listint(head->next));
}
