#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a
 * listint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting at 0
 *
 * Return: 1 if it succeeded,
 *        -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node_ptr = *head, *tmp;
	unsigned int i = 0;

	if (index == 0 && *head)
	{
		tmp = *head;
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}
	while (node_ptr)
	{
		if (index == i)
		{
			node_ptr->prev->next = node_ptr->next;
			if (node_ptr->next)
				node_ptr->next->prev = node_ptr->prev;
			free(node_ptr);
			return (1);
		}
		node_ptr = node_ptr->next;
		i++;
	}
	return (-1);
}
