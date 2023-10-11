#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm.
 * @array: Pointer to the first element of the array.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is found, return its index; otherwise, return -1.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t prev_bound = 0;
	size_t low = 0;
	size_t hight = 0;

	if (array == NULL)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		prev_bound = bound;
		bound *= 2;
	}

	if (bound >= size)
		bound = size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", prev_bound, bound);

	return (binary_search(array, prev_bound, bound, value));
}

/**
 * binary_search - Searches for a value in a sorted subarray of integers
 * using the Binary search algorithm.
 * @array: Pointer to the first element of the array.
 * @low: The index of the first element in the subarray.
 * @high: The index of the last element in the subarray.
 * @value: The value to search for.
 *
 * Return: If the value is found, return its index; otherwise, return -1.
 */
int binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid = (low + high) / 2;
	size_t i;
	size_t mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			if (i < high)
				printf("%d, ", array[i]);
			else
				printf("%d", array[i]);
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return (-1);
}

