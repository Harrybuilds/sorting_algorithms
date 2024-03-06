#include "sort.h"


/**
 * quick_sort - function to sort an array using merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 * Return: nothing is returned
*/
void quick_sort(int *array, size_t size)
{
	int low = 0,  pi; /* Start index of the array*/
	int high = size - 1; /* End index of the array*/

	if (size < 2) /* Base case: if size is 1 or 0, array is already sorted*/
		return;

	/* Partition the array using Lomuto scheme */
	pi  = partition(array, low, high);

	/* Recursively sort elements before and after partition */
	quick_sort(array, pi); /* Sort left subarray */
	quick_sort(array + pi + 1, size - pi - 1); /* Sort right subarray */
}

/**
 * swap - function to swap two elements in the array
 * @a: pointer to first element of array that is an integer
 * @b: pointer to second element of array that is an integer
 * return: nothing is returned
*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * partition - Lomuto partition scheme: picks the last element as the pivot
 * @arr: the array to be partitioned
 * @low: low part
 * @high: high part
 * Return: an integer value
*/

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; /* Select the pivot as the last element*/
	int i = low - 1; /* Index of the smaller element*/

	for (int j = low; j <= high - 1; j++)
	{
		/* If current element is smaller than or equal to pivot*/
		if (arr[j] <= pivot)
		{
			i++; /* Increment index of smaller element*/
			swap(&arr[i], &arr[j]); /* Swap current element with arr[i]*/
		}
	}
	swap(&arr[i + 1], &arr[high]); /* Swap pivot with arr[i+1] */
	return (i + 1); /* Return the partition index */
}

