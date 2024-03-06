#include "sort.h"

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 * list of integers with the node ahead of it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swapping: A pointer to the current swapping node of the cocktail algorithm.
 */
void swap_node_ahead(listint_t **head, listint_t **tail, listint_t **swapping)
{
	listint_t *temp = (*swapping)->next;

	if ((*swapping)->prev != NULL)
		(*swapping)->prev->next = temp;
	else
		*head = temp;
	temp->prev = (*swapping)->prev;
	(*swapping)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *swapping;
	else
		*tail = *swapping;
	(*swapping)->prev = temp;
	temp->next = *swapping;
	*swapping = temp;
}

/**
 * swap_node_behind - function to swap a node in a listint_t
 * doubly linked list of integers with the node behind it.
 * @hea: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swap_node: A pointer to the current swapping node of the cocktail algorithm
 */
void swap_node_behind(listint_t **hea, listint_t **tail, listint_t **swap_node)
{
	listint_t *temp = (*swap_node)->prev;

	if ((*swap_node)->next != NULL)
		(*swap_node)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*swap_node)->next;
	(*swap_node)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *swap_node;
	else
		*hea = *swap_node;
	(*swap_node)->next = temp;
	temp->prev = *swap_node;
	*swap_node = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers
 *in ascending order using the cocktail shaker algorithm.
 * @head: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **head)
{
	listint_t *tail, *swap_node;
	bool std = false;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (tail = *head; tail->next != NULL;)
		tail = tail->next;

	while (std == false)
	{
		std = true;
		for (swap_node = *head; swap_node != tail; swap_node = swap_node->next)
		{
			if (swap_node->n > swap_node->next->n)
			{
				swap_node_ahead(head, &tail, &swap_node);
				print_list((const listint_t *)*head);
				std = false;
			}
		}
		for (swap_node = swap_node->prev; swap_node != *head;
		     swap_node = swap_node->prev)
		{
			if (swap_node->n < swap_node->prev->n)
			{
				swap_node_behind(head, &tail, &swap_node);
				print_list((const listint_t *)*head);
				std = false;
			}
		}
	}
}
