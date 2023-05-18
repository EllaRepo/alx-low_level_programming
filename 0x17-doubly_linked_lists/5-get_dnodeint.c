#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index -  returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting at 0
 *
 * Return: the node at index
 *         NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *node_ptr = head;
	unsigned int n = 0;

	while (node_ptr)
	{
		if (index == n)
			return (node_ptr);
		node_ptr = node_ptr->next;
		n++;
	}
	return (NULL);
}
