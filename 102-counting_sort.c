#include "sort.h"

/**
 * counting_sort - function to sorts an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: nothing is returned
 *
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

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
*/

/**
 * counting_sort - function to sorts an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: nothing is returned
 */
void counting_sort(int *array, size_t size)
{
	    int *count, *sorted;
	    int max = array[0];

	    if (array == NULL || size < 2)
		    return;

	    /* Find the maximum element in the array */
	    for (size_t i = 1; i < size; i++)
	    {
		    if (array[i] > max)
			    max = array[i];
	    }

	    /* Allocate memory for count array and check for allocation failure */
	    count = malloc(sizeof(int) * (max + 1));
	    if (count == NULL)
		    return;

	    /* Allocate memory for sorted array and check for allocation failure */
	    sorted = malloc(sizeof(int) * size);
	    if (sorted == NULL)
	    {
		    free(count); /* Free allocated memory before returning */
		    return;
	    }

	    /* Initialize count array with zeros */
	    for (int i = 0; i <= max; i++)
		    count[i] = 0;

	    /* Count the occurrences of each element in the input array */
	    for (size_t i = 0; i < size; i++)
		    count[array[i]]++;

	    /* Modify count array to contain actual position of elements in sorted array */
	    for (int i = 1; i <= max; i++)
		    count[i] += count[i - 1];

	    /* print contents of the count array */
	    print_array(count, max + 1);
	    
	    /* Build the sorted array */
	    for (int i = size - 1; i >= 0; i--)
	    {
		    sorted[count[array[i]] - 1] = array[i];
		    count[array[i]]--;
	    }

	    /* Copy sorted array back to the input array */
	    for (size_t i = 0; i < size; i++)
		    array[i] = sorted[i];

	    /* Free dynamically allocated memory */
	    free(count);
	    free(sorted);
}
