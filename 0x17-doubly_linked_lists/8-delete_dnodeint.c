#include "lists.h"

/**
  * delete_dnodeint_at_index - this deletes a node at an index in doubly
  * linked list
  *
  * @head: a double pointer to first node of linked list
  * @index: an index to delete node at
  * Return: 1 on success, -1 if failure
  */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int j;
	dlistint_t *before, *after, *temp;

	before = *head;
	after = *head;

	if (!head || *head == NULL)
		return (-1);

	if (after)
		after = after->next;
	for (j = 0; after != NULL && j < index; j++)
	{
		before = before->next;
		after = after->next;
	}
	if (index == 0 && *head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	if (j == index && before != NULL)
	{
		temp = before;
		before = before->prev;
		free(temp);
		before->next = after;
		if (after)
			after->prev = before;
		return (1);
	}

	return (-1);
}
