#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: array to be sorted.
 * @size: size of the array.
 *
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int tmp;

	if (size == 0 || size == 1)
		return;
	while (i < size)
	{
		for (j = 0; j < size; j++)
		{
			if (j == size - 1)
				break;
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}	
		i++;
	}
}
