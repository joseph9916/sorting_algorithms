#include "sort.h"
#include <stdlib.h>

/**
 * swap_node - swaps the nodes
 * @prevnode: the previous node
 * @curnode: the current node
 */

void swap_node(listint_t *prevnode, listint_t *curnode)
{
	listint_t *tempnode;

	tempnode = prevnode->prev;
	prevnode->prev = curnode;
	curnode->prev = tempnode;
	if (tempnode)
		tempnode->next = curnode;
	tempnode = curnode->next;
	curnode->next = prevnode;
	prevnode->next = tempnode;
	if (tempnode)
		tempnode->prev = prevnode;
}

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: linked list to sort
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curnode, *present_node, *prevnode, *tempnode;

	if (!list)
		return;
	present_node = (*list)->next;
	if (!present_node)
		return;
	if (!present_node->next)
	{
		curnode = present_node;
		prevnode = curnode->prev;
		if (curnode->n < prevnode->n)
		{
			swap_node(prevnode, curnode);
			*list = curnode;
			print_list(*list);
		}
		return;
	}
	while (present_node)
	{
		curnode = present_node;
		present_node = present_node->next;
		prevnode = curnode->prev;
		while (prevnode)
		{
			if (prevnode->n > curnode->n)
			{
				swap_node(prevnode, curnode);
				tempnode = curnode;
				curnode = prevnode;
				prevnode = tempnode;
				if (curnode == *list)
					*list = prevnode;
				print_list(*list);
			}
			curnode = curnode->prev;
			prevnode = curnode->prev;
		}
	}
}
