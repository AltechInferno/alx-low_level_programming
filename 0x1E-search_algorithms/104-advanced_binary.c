#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using binary search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 * Otherwise, the index where the value is located.
 *
 * Description: Prints the array (subarray) being searched after each change.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		size_t i = left;

		printf("Searching in array: ");
		while (i < right)
		{
			printf("%d, ", array[i]);
			i++;
		}
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;

		if (array[i] == value)
		{
			if (i > 0 && array[i - 1] == value)
			{
				right = i;
				continue;
			}
			return (i);
		}

		if (array[i] < value)
			left = i + 1;
		else
			right = i;
	}

	return (-1);
}

