#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given
 *                           index of a listint_t list.
 * @head: A pointer to the address of the head of the listint_t list.
 * @index: The index of the node to be deleted - indices start at 0.
 *
 * Return: On success - 1.
 *         On failure - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *copy = *head; /* declare variables */

	unsigned int node; /* declare node variable */

	if (copy == NULL) /* check if list is empty */
		return (-1);

	if (index == 0) /* check if node to delete is head */
	{
		*head = (*head)->next; /* point head to next node */
		free(copy); /* free memory of original head */
		return (1); /* return success */
	}

	for (node = 0; node < (index - 1); node++) /* iterate to node before target */
	{
		if (copy->next == NULL) /* check if next node is NULL */
			return (-1);

		copy = copy->next; /* move to next node */
	}

	tmp = copy->next; /* store target node */
	copy->next = tmp->next; /* point previous node to next node */
	free(tmp); /* free memory of target node */

	return (1); /* return success */
}
