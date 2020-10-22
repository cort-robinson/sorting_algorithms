#include "sort.h"

/**
 * swap - Swaps two elements of array.
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
 * selection_sort - Sorts an array of ints in ascending order
 * using the Selection sort algorithm.
 *
 * @array: Array to sort.
 * @size: Size of array.
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, mindex;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mindex = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[mindex])
				mindex = j;
		swap(&array[mindex], &array[i]);
		if (array[mindex] != array[i])
			print_array(array, size);
	}
}
