#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint -  deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n)
 * @head: pointer to the head of the list
 *
 * Return: if the linked list is empty return 0
 */
int pop_listint(listint_t **head)
{
	listint_t *hd = *head;
	int n = 0;

	if (hd)
	{
		*head = (*head)->next;
		n = hd->n;
		free(hd);
	}
	return (n);
}
