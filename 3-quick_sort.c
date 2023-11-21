#include "sort.h"

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

/**
 * partition - partitions an unsorted array
 * @array: array to partition
 * @low: lower bound
 * @high: upper bound
 * @size: size of the array
 *
 * Return: index of partition
 */

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	size_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != (int) j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}
	}
	if (j != (size_t) (i + 1))
	{
		swap(&array[j], &array[i + 1]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - sorts an array using the quick sort algorithm
 * @array: the unsorted array
 * @size: size of the array
 * @low: lower bound of array
 * @high: upper bound of array
 *
 * Return: Nothing
 */

void quick_sort_helper(int *array, size_t size, size_t low, size_t high)
{
	if (low < high)
	{
		size_t pos = partition(array, low, high, size);

		if (pos > low)
			quick_sort_helper(array, size, low, pos - 1);
		if (pos + 1 < high)
			quick_sort_helper(array, size, pos + 1, high);
	}
}

/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: the unsorted array
 * @size: size of the array
 *
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, size, 0, size - 1);
}
