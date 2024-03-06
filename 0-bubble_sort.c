#include "sort.h"

/**
 * bubble_sort - function to bubble sort an array of integers
 * @array: a pointer to an array of integers
 * @size: size of the array
 * Return: nothing is returned
 */

void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;

    if (array == NULL)
	    return
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
        }
    }
}
