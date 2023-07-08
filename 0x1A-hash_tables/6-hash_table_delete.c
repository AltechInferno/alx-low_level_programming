#include "hash_tables.h"
/**
 * hash_table_delete - this deletes the hash table
 * @ht: the hash table
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	size_t j = 0;
	hash_node_t *array = NULL, *tp = NULL;

	if (!ht)
		return;
	while (j < ht->size)
	{
		if (ht->array[j])
		{
			array = ht->array[j];
			while (array)
			{
				free(array->key);
				free(array->value); /*empty string???*/
				tp = array;
				array = array->next;
				free(tp);
			}
		}
		j++;
	}
	free(ht->array);
	free(ht);
}
