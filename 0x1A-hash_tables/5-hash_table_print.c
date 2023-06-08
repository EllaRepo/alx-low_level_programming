#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: is the hash table
 *
 * Return: None
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp;
	unsigned long int index;
	char *sepa;

	if (ht == NULL)
		return;
	sepa = "";
	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		tmp = ht->array[index];
		while (tmp)
		{
			printf("%s\'%s\': \'%s\'", sepa, tmp->key, tmp->value);
			sepa = ", ";
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
