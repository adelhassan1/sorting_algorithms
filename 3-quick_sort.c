#include "sort.h"
/**
 * partition - dividing array into partitions and swaps.
 * @array: array to be divided.
 * @lo: low index.
 * @hi: high index.
 * @size: size of array.
 *
 * Return: pivot.
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j, holder;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				holder = array[i];
				array[i] = array[j];
				array[j] = holder;
				print_array(array, size);
			}
		}
	}
	if (pivot < array[i + 1])
	{
		holder = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = holder;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sorting - sorting partitions.
 * @array: array to be sorted.
 * @lo: low index.
 * @hi: hight index.
 * @size: size of array.
 *
 * Return: nothing.
 */
void sorting(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		sorting(array, lo, p - 1, size);
		sorting(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: array to be sorted.
 * @size: size of array.
 *
 * Return: Nothing.
 */
void quick_sort(int *array, size_t size)
{
	size_t lo, hi;

	if (size == 0 || size == 1)
		return;
	lo = 0;
	hi = size - 1;
	sorting(array, lo, hi, size);
}
