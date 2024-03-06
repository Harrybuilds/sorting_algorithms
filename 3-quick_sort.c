#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - function to swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 * return: nothing is returned
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according
 * to the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The array size 
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1, j;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[right]);
	print_array(array, size);
	return i + 1;
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The array size.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: function that uses the Lomuto partition scheme.
 * Return: nothing is returned
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - function to sort an array of integers in
 * ascending order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The array size
 *
 * Description: This function uses the Lomuto partition scheme. 
 * and prints the array after each swap of two elements.
 * Return: nothing is returned
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
