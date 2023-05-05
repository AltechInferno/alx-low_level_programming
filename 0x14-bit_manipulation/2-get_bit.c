#include "main.h"

/**
 * get_bit - Gets the value of a bit at the given index
 * @n: The number
 * @index: The index (starting from 0) of the bit required
 *
 * Return: The value of the bit (0 or 1) at the given index, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	return ((n >> index) & 1);
}

