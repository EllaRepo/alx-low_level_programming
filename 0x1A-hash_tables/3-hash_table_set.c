#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: is the hash table you want to add or update the key/value to
 * @key: is the key
 * @value: is the value associated with the key
 *
 * Return: 1 if it succeeded,
 *         0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *elem, *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);
	elem = malloc(sizeof(hash_node_t));
	if (!elem)
		return (0);
	elem->key = strdup(key);
	elem->value = strdup(value);
	elem->next = NULL;

	index = key_index((const unsigned char *)key, ht->size);

	if (ht->array[index])
	{
		tmp = ht->array[index];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
	{
		ht->array[index] = elem;
	}
	return (1);
}
