#include "sort.h"
#include <stddef.h>


/**
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (size < 2)
		return;
	else if (size == 2)
	{
		if (array[0] > array[1])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
			print_array(array, size);
		}
		return;
	}
	else
		for (i = 0; i < size; i++)
		{
			min_index = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[min_index] > array[j])
					min_index = j;
			}
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			if (min_index != i)
				print_array(array, size);
		}
}
