#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t node_num = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		node_num++;
		h = h->next;
	}

	return (node_num);
}
