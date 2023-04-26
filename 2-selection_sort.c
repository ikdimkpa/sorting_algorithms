#include "sort.h"

/**
 * swap - Swaps two ints in an array.
 * @a: First int.
 * @b: Second int.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * selection_sort - Using the selection sort algorithm to
 *                  sort an array of ints.
 * @array: Array of ints.
 * @size: Size of array.
 */
void selection_sort(int *array, size_t size)
{
	int *mini;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mini = array + i;
		for (j = i + 1; j < size; j++)
			mini = (array[j] < *mini) ? (array + j) : mini;

		if ((array + i) != mini)
		{
			swap(array + i, mini);
			print_array(array, size);
		}
	}
}
