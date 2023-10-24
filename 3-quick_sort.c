#include "sort.h"
#include <stdio.h>

/**
 * partition - sorts a partition of an array
 * @a: array to sort
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: pivot index
 */

int partition(int *a, int low, int high, size_t size)
{
	int pivot, i, temp, current;

	current = low;
	pivot = a[low];
	for (i = low + 1; i < high; i++)
	{
		if (a[i] < pivot)
		{
			current++;
			if (i != current)
			{
				temp = a[i];
				a[i] = a[current];
				a[current] = temp;
				print_array(a, size);
			}
		}
	}
	if (current != low)
	{
		temp = a[low];
		a[low] = a[current];
		a[current] = temp;
		print_array(a, size);
	}
	return (current);
}

/**
 * quicksort - forms a recursive quicksort function
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: Nothing
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p; /*array_sub*/

	if (low >= high || low < 0)
		return;
	p = partition(array, low, high, size);

	quicksort(array, low, p, size);
	quicksort(array, p + 1, high, size);
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array sort
 * @size: size of array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort(array, 0, size, size);
}
