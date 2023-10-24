#include "sort.h"


/**
 * swap - two nodes
 * @prevnode: previous node
 * @curnode: current node
 * Return: Nothing
 */

void swap(listint_t *prevnode, listint_t *curnode)
{
	listint_t *tempnode;

	tempnode = prevnode->prev;
	prevnode->prev = curnode;
	curnode->prev = tempnode;
	if (tempnode)
		tempnode->next = curnode;
	tempnode = curnode->next;
	prevnode->next = tempnode;
	curnode->next = prevnode;
	if (tempnode)
		tempnode->prev = prevnode;
}


/**
 * insertion_sort_list - sort a linked list with insertion sort algorithm
 * @list: linked list to sort
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *present_node = *list, *prevnode, *curnode, *tempnode;

	if (!present_node)
		return;
	if (!present_node->next)
		return;
	while (present_node)
	{
		prevnode = present_node;
		present_node = present_node->next;
		curnode = present_node;
		while (curnode && (curnode->n < prevnode->n) && curnode->prev)
		{
			swap(prevnode, curnode);
			tempnode = prevnode;
			prevnode = curnode;
			curnode = tempnode;
			if (curnode == *list)
				*list = prevnode;
			curnode = curnode->prev;
			print_list(*list);
			if (prevnode->prev)
				prevnode = prevnode->prev;
		}
	}
}
