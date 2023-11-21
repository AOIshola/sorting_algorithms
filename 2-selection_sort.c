#include "sort.h"

/**
 * selection_sort - uses the selection sort algorithm
 * to sort an array
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, pos;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		pos = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				pos = j;
			}
		}
		if (pos > 0)
		{
			swap(&array[i], &array[pos]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two values
 * @first: the first value
 * @second: the second value
 *
 * Return: Nothing.
 */

void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}
