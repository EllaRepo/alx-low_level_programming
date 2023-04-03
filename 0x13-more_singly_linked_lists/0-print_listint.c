#include <stdio.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to listint_t
 *
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *h)
{
	if (!h)
		return (0);
	printf("%i\n", h->n);
	return (1 + print_listint((const listint_t *) h->next));
}
