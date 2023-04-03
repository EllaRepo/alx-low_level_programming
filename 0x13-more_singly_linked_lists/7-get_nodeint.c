#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index -  returns the nth node of a listint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting at 0
 *
 * Return: the node at index
 *         NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *node_ptr = head;
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
