#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to dlistint_t
 *
 * Return: Number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int cnt = 0;

	if (h)
		for (; h; h = h->next, cnt++)
			printf("%d\n", h->n);
	return (cnt);
}
