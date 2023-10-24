#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - selection sort algorithm
 * @array: array to sort
 * @size: size of array to sort
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}
		if (i != min_index)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
