#include <stddef.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: pointer to list_t
 *
 * Return: Number of nodes
 */
size_t list_len(const list_t *h)
{
	if (!h)
		return (0);
	return (1 + list_len((const list_t *) h->next));
}
