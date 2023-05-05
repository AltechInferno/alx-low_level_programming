#include "main.h"

/**
 * get_endianness - Checks if the system is big endian or little endian
 *
 * Return: 1 if little endian, 0 otherwise
 */
int get_endianness(void)
{
	unsigned int test = 1;
	char *endian = (char *)&test;

	if (*endian)
	{
		return (1);
	}
	return (0);
}


