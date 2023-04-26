#include "sort.h"

/**
 * swap - Swaps two ints in array.
 * @a: The 1st int.
 * @b: The 2nd int.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t s, len = size;
	bool bub = false;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (s = 0; s < len - 1; s++)
		{
			if (array[s] > array[s + 1])
			{
				swap(array + s, array + s + 1);
				print_array(array, size);
				bub = false;
			}
		}
		len--;
	}
}
