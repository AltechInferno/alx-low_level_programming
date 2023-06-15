#include "lists.h"

/**
  * print_dlistint- this prints elements of a linked list
  *
  * @h: this is the first node of the linked list
  * Return: this is the number of elements in the linked list
  */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);

		h = h->next;

		count++;
	}

	return (count);
}

