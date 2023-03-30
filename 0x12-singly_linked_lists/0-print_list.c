#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to list_t
 *
 * Return: Number of nodes
 */
size_t print_list(const list_t *h)
{
	if (!h)
		return (0);
	if (h->str)
		printf("[%d] %s\n", h->len, h->str);
	else
		printf("[0] %s\n", "(nil)");
	return (1 + print_list((const list_t *) h->next));
}
