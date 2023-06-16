#include "lists.h"

/**
  * get_dnodeint_at_index - this gets a node at an index
  *
  * @head: this is the first node of the linked list
  * @index: this is the index at which to find the node
  * Return: this is the address of wanted node, or NULL if not within list
  */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int j;

	for (j = 0; head != NULL && j < index; j++)
		head = head->next;

	if (j == index)
		return (head);

	return (NULL);
}
