#include "main.h"

/**
 * set_bit - This Sets a bit at the specified index to 1
 * @n: Pointer to the number to be modified
 * @index: Index of the bit to be set (starting from 0)
 *
 * Return: 1 on success, -1 on failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || (index > (sizeof(unsigned long int) * 8) - 1))
		return (-1);

	*n |= (1 << index);
	return (1);
}


