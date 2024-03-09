#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: nothing is returned
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max;
	size_t i;

	if (array == NULL || size < 2)
	return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];

	for (i = size - 1; i != (size_t)-1; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
