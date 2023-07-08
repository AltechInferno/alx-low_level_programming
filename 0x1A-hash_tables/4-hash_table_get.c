#include "hash_tables.h"

/**
 * hash_table_get - This redeems a value related to a key
 * @ht: a hash table
 * @key: a key
 * Return: the value associated with the key
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node = NULL;
	unsigned long int i;

	if (!ht || !key)
	{
		return (NULL);
	}
	i = key_index((const unsigned char *)key, ht->size);
	node = ht->array[i];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			break;
		node = node->next;
	}
	if (!node)
	{
		return (NULL);
	}
	return (node->value);
}
