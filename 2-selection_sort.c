#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: array to be sorted.
 * @size: size of array.
 *
 * Return: nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, checker;
	int tmp;

	if (size == 0 || size == 1)
		return;
	for (i = 0; i < size; i++)
	{
		checker = i;
		if (i == size - 1)
			break;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[checker])
				checker = j;
		}
		if (i != checker)
		{
				tmp = array[i];
				array[i] = array[checker];
				array[checker] = tmp;
				print_array(array, size);
		}	
	}
}
