#include "hash_tables.h"
/**
 * key_index - This gives you the index of a key
 * @key: the key
 * @size: the size of the array
 * Return: the index at which the key/value pair should be stored
 * in the array of the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int i;

	if (!key || !size)
	{
		return (0);
	}
	i = hash_djb2(key) % size;
	return (i);
}
