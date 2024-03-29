#include "main.h"

/**
 * print_binary - This will Print the binary representation of a number
 * @n: Number to be printed in binary format
 * Author - Alhassan Abukari Wunpini
 * Return: void
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}


