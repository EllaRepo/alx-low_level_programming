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
	const listint_t *prev = head;
	size_t i = 0;

	for (; head != NULL; prev = head, head = head->next, i++)
	{
		if (prev < head)
		{
			printf("-> [%p] %i\n", (void *) head, head->n);
			exit(98);
		}
		printf("[%p] %i\n", (void *) head, head->n);
	}
	return (i);
}
