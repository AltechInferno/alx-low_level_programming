#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
    size_t node_num = 0;  /* variable to count the number of nodes in the list */

    /* traverse the list and print the value of each node */
    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        node_num++;
    }

    return (node_num);
}

