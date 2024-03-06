#include "sort.h"

/**
 * shell_sort - function to sorting an array in ascending
 * order using the shell algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 * return: nothing is returned
*/
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	if (array == NULL)
		return;
	/* Generate Knuth sequence */
	while (interval <= size / 3)
	{
		interval = interval * 3 + 1;
	}

	/* Iterate over intervals */
	while (interval > 0)
	{
		/* Perform insertion sort with current interval */
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}

		/* Decrease interval according to Knuth sequence*/
		interval = (interval - 1) / 3;
		print_array(array, size);
	}

}
