#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: the index of the list where the new node should be added
 * @n: integer
 *
 * Return: the address of the new node
 *         NULL if it failed or if it is not possible to add the
 *         new node at index idx
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node_ptr, *tmp;
	unsigned int i = 0;

	if (idx == 0)
	{
		tmp = add_dnodeint(h, n);
	}
	else
	{
		node_ptr = *h;
		if (node_ptr != NULL)
			while (node_ptr->prev != NULL)
				node_ptr = node_ptr->prev;
		while (node_ptr)
		{
			if (idx == i + 1)
			{
				if (node_ptr->next)
				{
					tmp = malloc(sizeof(dlistint_t));
					if (!tmp)
						return (NULL);
					tmp->n = n;
					tmp->next = node_ptr->next;
					tmp->prev = node_ptr;
					(node_ptr->next)->prev = tmp;
					node_ptr->next = tmp;
				}
				else
				{
					tmp = add_dnodeint_end(h, n);
				}
				return (tmp);
			}
			node_ptr = node_ptr->next;
			i++;
		}
	}
	return (NULL);
}
