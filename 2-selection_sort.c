#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

	/* Find the index of the minimum element in the unsorted part of the array */
	for (j = i + 1; j < size; j++)
		{
		if (array[j] < array[min_index])
		min_index = j;
		}

	/* Swap the minimum element with the first element of the unsorted part */
	if (min_index != i)
		{
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		/* Print the array after each swap */
		print_array(array, size);
		}
	}
}
