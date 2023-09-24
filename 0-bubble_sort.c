#include "sort.h"


/**
 * bubble_sort - a function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 2)
	{
		return;
	}
	else if (size == 2)
	{
		/*[20, 19] = [19, 20]*/
		if (array[1] < array[0])
		{
			temp = array[0];
			array[0] = array[1];
			array[1] = temp;
			print_array(array, size);
		}
		return;
	}
	else
	{
		for (i = 0; i < size; i++)
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
}
