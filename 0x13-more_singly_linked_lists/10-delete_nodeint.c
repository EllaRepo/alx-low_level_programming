#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a
 * listint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node, starting at 0
 *
 * Return: 1 if it succeeded,
 *        -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node_ptr = *head, *tmp;
	unsigned int i = 0;

	if (index == 0 && *head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	while (node_ptr)
	{
		if (index == i + 1 && node_ptr->next)
		{
			tmp = node_ptr->next;
			node_ptr->next = tmp->next;
			free(tmp);
			return (1);
		}
		node_ptr = node_ptr->next;
		i++;
	}
	return (-1);
}
