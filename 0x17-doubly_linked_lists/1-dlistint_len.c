#include <stdio.h>
#include "lists.h"

/**
 * dlistint_len - prints all the elements of a dlistint_t list
 * @h: pointer to dlistint_t
 *
 * Return: Number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int cnt = 0;

	if (h)
		for (; h; h = h->next, cnt++)
			;
	return (cnt);
}
