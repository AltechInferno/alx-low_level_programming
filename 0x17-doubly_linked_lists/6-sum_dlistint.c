#include "lists.h"

/**
  * sum_dlistint - these are the sums the data of a linked list
  *
  * @head: the first element of linked list
  * Return: 0 if empty, sum otherwise
  */
int sum_dlistint(dlistint_t *head)
{
	int total_sum = 0;

	while (head)
	{
		total_sum += head->n;
		head = head->next;
	}

	return (total_sum);
}
