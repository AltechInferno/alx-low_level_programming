#include "lists.h"

/**
  * add_dnodeint - this adds a new node at the beginning of a linked list
  *
  * @head: this is a double pointer to head of linked list
  * @n: this is an integer value for new node
  * Return: this is an address of new element or NULL for failure
  */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t *));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;

	temp = *head;
	new_node->next = temp;
	*head = new_node;
	if (temp)
		temp->prev = *head;

	return (new_node);
}
