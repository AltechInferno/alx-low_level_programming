#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in an array of
 * integers using the Jump search algorithm
 *
 * @list: input list
 * @size: size of the array
 * @value: value to search for
 * Return: listint_t node containing the value, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = sqrt(size);
	listint_t *prev = NULL;

	if (list == NULL || size == 0)
		return (NULL);

	while (list->index < size && list->n < value)
	{
		prev = list;
		list = list->next;
		if (list->index >= size)
			break;
		printf("Value checked at index [%d] = [%d]\n", (int)list->index,
				list->n);
	}

	printf("Value found between indexes [%d] and [%d]\n", (int)prev->index,
			(int)list->index);

	while (prev && prev->index <= list->index)
	{
		printf("Value checked at index [%d] = [%d]\n",
				(int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}

