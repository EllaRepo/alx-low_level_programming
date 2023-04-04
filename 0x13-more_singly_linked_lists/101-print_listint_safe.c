#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_ptr -  frees a listint_ptr_t list
 * @head: pointer to the head of the list
 *
 * Return: None
 */
void free_listint_ptr(listint_ptr_t *head)
{
	if (head)
	{
		free_listint_ptr(head->next);
		free(head);
	}
}
/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to listint_t
 *
 * Return: Number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	listint_ptr_t *node_ptr, *tmp;
	size_t i = 0;

	node_ptr = NULL;
	while (head != NULL)
	{
		tmp = node_ptr;
		while (tmp)
		{
			if ((void *) head == tmp->list_ptr)
			{
				printf("-> [%p] %i\n", (void *) head, head->n);
				free_listint_ptr(tmp);
				return (i);
			}
			tmp = tmp->next;
		}
		tmp = malloc(sizeof(listint_ptr_t));
		if (!tmp)
		{
			free_listint_ptr(node_ptr);
			exit(98);
		}
		tmp->next = node_ptr;
		tmp->list_ptr = (void *) head;
		node_ptr = tmp;
		printf("[%p] %i\n", tmp->list_ptr, head->n);
		head = head->next;
		i++;
	}
	free_listint_ptr(node_ptr);
	return (i);
}
