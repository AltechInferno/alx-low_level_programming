#include "lists.h"

/**
  * free_dlistint - this frees a linked list
  *
  * @head: this is the first member of list
  * Return: void
  */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp = NULL;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
