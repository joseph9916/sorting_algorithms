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
 * cocktail_sort_list - sort with cocktail sort algorithm
 * @list: list to sort
 * Return: Nothing
 */


void cocktail_sort_list(listint_t **list)
{
	listint_t *beg_list = *list, *end_list = NULL, *curnode;
	listint_t *nextnode, *tempnode, *prevnode;
	int i = 0, j;

	if (!beg_list)
		return;
	if (!beg_list->next)
		return;
	curnode = beg_list;
	while (beg_list != end_list)
	{
		nextnode = curnode->next;
		j = i;
		while (curnode && curnode->next != end_list)
		{
			if (curnode->n > nextnode->n)
			{
				swap(curnode, nextnode);
				tempnode = curnode;
				curnode = nextnode;
				nextnode = tempnode;
				if (nextnode == *list)
					*list = curnode;
				print_list(*list);
				i++;
			}
			curnode = curnode->next;
			nextnode = nextnode->next;
		}
		if (i == j)
			return;
		j = i;
		end_list = curnode;
		prevnode = end_list;
		curnode = curnode->prev;
		while (curnode && curnode != beg_list->prev)
		{
			if (curnode->n > prevnode->n)
			{
				swap(curnode, prevnode);
				tempnode = curnode;
				curnode = prevnode;
				prevnode = tempnode;
				if (prevnode == *list)
				{
					*list = curnode;
					beg_list = curnode;
				}
				print_list(*list);
				i++;
			}
			curnode = curnode->prev;
			prevnode = prevnode->prev;
		}
		if (i == j)
			return;
		beg_list = beg_list->next;
		curnode = beg_list;
	}
}
