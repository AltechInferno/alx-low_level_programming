#include "hash_tables.h"

/**
 * hash_table_print - This prints a hash table
 * @ht: a hash table
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node = NULL;
	unsigned long int j = 0;
	int result = 0;

	if (!ht)
	{
		return;
	}
	putchar('{');
	while (j < ht->size)
	{
		node = ht->array[j];
		while (node)
		{
			if (result == 1)
			{
				printf(", ");
			}
			printf("'%s': '%s'", node->key, node->value);
			node = node->next;
			result = 1;
		}
		j++;
	}
	printf("}\n");
}
