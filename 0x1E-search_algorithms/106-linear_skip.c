#include "search_algos.h"

/**
 * linear_skip - searches for a value in a skip list
 *
 * @list: input list
 * @value: value to search for
 * Return: skiplist_t node containing the value, or NULL if not found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	if (list == NULL)
		return (NULL);

	skiplist_t *current = list;
	skiplist_t *next = NULL;

	while (current)
	{
		next = current->express;
		printf("Value checked at index [%d] = [%d]\n", (int)next->index, next->n);

		if (next->n >= value)
		{
			printf("Value found between indexes [%d] and [%d]\n", (int)current->index,
					(int)next->index);

			while (current)
			{
				printf("Value checked at index [%d] = [%d]\n", (int)current->index,
						current->n);
				if (current->n == value)
					return (current);
				if (current->n > value)
					return (NULL);
				current = current->next;
			}
		}
		current = next;
	}
	return (NULL);
}

