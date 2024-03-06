#include "sort.h"

/**
 * selection_sort - function that use the selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing is returned
*/

void selection_sort(int *array, size_t size)
{
	size_t i, min_index, j, k;
	int temp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/* Find the index of the minimum element in the unsorted part of the array*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		/* Swap the minimum element with the first element of the unsorted part */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			/* Print the array after each swap */
			print_array(array, size);
			printf("\n");
		}
	}
}
