#include "lists.h"

/**
 * add_nodeint - add a new node to the beginning of a linked list
 * @head: pointer to the head of the list
 * @n: integer value to store in the new node
 *
 * Return: pointer to the new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	int a;
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}

	a = n;
	/*
	 * Uncomment this code to check for allocation failure
	 *
	 * if (!a)
	 * {
	 *     free(new);
	 *     return (NULL);
	 * }
	 */

	new->n = a;
	new->next = *head;
	*head = new;

	return (new);
}
