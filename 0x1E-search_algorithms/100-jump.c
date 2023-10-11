#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump search algorithm.
 * @array: Pointer to the first element of the array.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is found, return its index; otherwise, return -1.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size);
	size_t left = 0;
	size_t right = 0;

	if (array == NULL)
		return (-1);

	while (right < size && array[right] < value)
	{
		left = right;
		right += jump;
		printf("Value checked array[%lu] = [%d]\n", right, array[right]);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	while (left <= right)
	{
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);
		if (array[left] == value)
			return (left);

		left++;
	}

	return (-1);
}

