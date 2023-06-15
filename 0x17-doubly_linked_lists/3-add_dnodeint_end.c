#include "lists.h"

/**
  * add_dnodeint_end - this adds node to end of linked list
  *
  * @head: this is a double pointer to head of linked list
  * @n: this is a value for new node
  * Return: this is the address of the new node or NULL on failure
  */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	if (head == NULL)
		return (NULL);

	temp = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		new_node->prev = NULL;
		return (new_node);
	}
	while (temp && temp->next)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}
