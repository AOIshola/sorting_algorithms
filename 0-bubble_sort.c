#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the bubble sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag, temp;

	for (i = 0 ; i < size ; i++)
	{
		flag = 0;
		for (j = 0 ; j < size - (1 + i) ; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
