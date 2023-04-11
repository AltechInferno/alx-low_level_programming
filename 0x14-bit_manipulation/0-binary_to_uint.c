#include "main.h"

/**
 * binary_to_uint - converts a binary to an unsigned int
 * @b: binary number as a string
 *
 * Return: the converted value
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int d = 0;
	int s = 0, base = 1;

	if (!b)
		return (0);

	while (b[s])
		s++;

	while (s)
	{
		d += ((b[s - 1] - '0') * base);
		base *= 2;
		s--;
	}
	return (d);
}

/**
 * check_valid_string - checks if a string has only 0's and 1's
 * @b: string to be checked
 *
 * Return: 1 if the string contains only 0's and 1's, 0 otherwise
 */
int check_valid_string(const char *b)
{
	if (!b)
		return (0);

	while (*b)
	{
		if (*b != '1' && *b != '0')
			return (0);
		b++;
	}
	return (1);
}

