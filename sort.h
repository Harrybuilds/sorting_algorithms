#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void swap_node_ahead(listint_t **head, listint_t **tail, listint_t **swapping);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **head);
void merge_sort(int *array, size_t size);

#endif
