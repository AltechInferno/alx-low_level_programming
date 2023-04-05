#include "lists.h"

/**
 * free_listint2 - frees a linked list and sets head to NULL
 * @head: pointer to the head of the linked list
 *
 * This function frees the memory of a linked list and sets the head pointer to
 * NULL. If the head pointer is already NULL, this function does nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *next;

	if (head == NULL)
		return;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

