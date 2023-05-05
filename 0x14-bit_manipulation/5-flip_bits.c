#include "main.h"

/**
 * flip_bits - Gets the number of bits to flip to get from n to m
 * @n: The initial number
 * @m: The final number
 *
 * Return: The number of flipped bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flipped = n ^ m;
	int count = 0;

	while (flipped)
	{
		if (flipped & 1)
			count++;
		flipped >>= 1;
	}
	return (count);
}


