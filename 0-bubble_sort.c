#include "sort.h"

/**
 * swap - Swaps two integer values in array.
 *
 * @x: int 1.
 * @y: int 2.
 */

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Sorts an array of ints in ascending order
 * using the bubble sort algorithm.
 *
 * @array: Pointer to the array to sort.
 * @size: Size of array.
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
		if (array[j] > array[j + 1])
		{
			swap(&array[j], &array[j + 1]);
			print_array(array, size);
		}
}
