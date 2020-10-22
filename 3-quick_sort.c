#include "sort.h"

/**
 * swap - Swaps two array elements.
 *
 * @x: First element.
 * @y: Second element.
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * partition - Lomuto partition scheme.
 *
 * @array: Array to evaluate.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of index.
 *
 * Return: Next index position for recursive_sorter.
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}

/**
 * recursive_sorter - Sorts an array of ints in ascending order
 * recursively using the Quick sort algorithm.
 *
 * @array: Array to sort.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of array.
 */

void recursive_sorter(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = partition(array, low, high, size);
		recursive_sorter(array, low, index - 1, size);
		recursive_sorter(array, index + 1, high, size);
	}
}

/**
 * quick_sort - Calls the recursive_sorter function to sort
 * an array using the Quick sort algorithm.
 *
 * @array: Array to sort.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	recursive_sorter(array, 0, size - 1, size);
}
