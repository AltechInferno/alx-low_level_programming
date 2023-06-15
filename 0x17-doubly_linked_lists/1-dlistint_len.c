#include "lists.h"

/**
  * dlistint_len - this block returns number of elements in 
  * a linked list
  *
  * @h: this is the first node of linked list
  * Return: the number of elements in the linked list
  */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}

	return (count);
}

