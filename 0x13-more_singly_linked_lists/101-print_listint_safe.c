#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to listint_t
 *
 * Return: Number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *node_ptr = head, *prev = head;
	size_t i;

	for (i = 0; node_ptr; i++)
	{
		if (prev < node_ptr)
		{
			printf("-> [%p] %i\n", (void *) node_ptr, node_ptr->n);
			exit(98);
		}
		printf("[%p] %i\n", (void *) node_ptr, node_ptr->n);
		prev = node_ptr;
		node_ptr = node_ptr->next;
	}
	return (i);
}
