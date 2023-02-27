#include "main.h"

/**
 * swap_int - swap the values of two integers
 * Return: nothing
 */

void swap_int(int *a, int *b)
{
	int s;

	s = *a;
	*a = *b;
	*b = s;
}
