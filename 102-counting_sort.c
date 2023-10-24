#include "sort.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * counting_sort - using counting sort algorithm to sort an array
 * @array: array to sort
 * @size: size of array
 */


void counting_sort(int *array, size_t size)
{
	size_t i;
	int *counting_array, *sorted_array, j, max;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc(sizeof(int) * (max + 1));
	if (!counting_array)
		return;
	for (j = 0; j < (max + 1); j++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (j = 0; j < max; j++)
	{
		counting_array[j + 1] = counting_array[j + 1] + counting_array[j];
	}
	print_array(counting_array, (max + 1));
	sorted_array = malloc(size);
	if (!sorted_array)
	{
		free(counting_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		j = counting_array[array[i]];
		sorted_array[j - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(counting_array);
	free(sorted_array);
}
