#include "main.h"
/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary number as a string
 * Author: Alhassan Abukari Wunpini
 * Return: the converted value, or 0 if invalid characters or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0;
	int str_len = 0, base = 1;

	if (!b)
		return (0);

	while (b[str_len] != '\0')
		str_len++;

	while (str_len)
	{
		if (b[str_len - 1] != '0' && b[str_len - 1] != '1')
			return (0);

		decimal += ((b[str_len - 1] - '0') * base);
		base *= 2;
		str_len--;
	}

	return (decimal);
}

