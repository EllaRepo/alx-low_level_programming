#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: is the size of the array
 *
 * Return: Returns a pointer to the newly created hash table
 *         NULL - If something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = NULL;
	hash_node_t **arr = NULL;
	unsigned long int i;

	hash_table = malloc(sizeof(hash_table_t));
	if (!hash_table)
		return (NULL);
	arr = malloc(sizeof(hash_node_t *) * size);
	if (!arr)
		return (NULL);
	for (i = 0; i < size; i++)
		arr[i] = NULL;
	hash_table->size = size;
	hash_table->array = arr;
	return (hash_table);
}
