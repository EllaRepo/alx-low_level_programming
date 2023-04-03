#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return:  a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *node_ptr1, *node_ptr2;

	if (!head)
		return (NULL);
	if (!((*head)->next))
		return (*head);

	node_ptr2 = (*head)->next;
	node_ptr1 = *head;
	node_ptr1->next = NULL;
	*head = node_ptr2;
	node_ptr2 = node_ptr2->next;
	(*head)->next = node_ptr1;
	while (node_ptr2)
	{
		node_ptr1 = *head;
		*head =  node_ptr2;
		node_ptr2 = node_ptr2->next;
		(*head)->next = node_ptr1;
	}
	return (*head);
}
