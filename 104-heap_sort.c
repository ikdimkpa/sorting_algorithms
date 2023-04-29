#include "sort.h"

void swap(int *x, int *y);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap - Swaps two ints in array.
 * @x: First int to swaped.
 * @y: Second int to be swaped.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *xa;
	*x = *y;
	*y = temp;
}

/**
 * max_heapify - Turns a binary tree into complete binary heap.
 * @array: Array of ints representing a binary tree.
 * @size: Size of the array/tree.
 * @base: Index of the base row of the tree.
 * @root: Root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts array of ints in ascending
 *             order using the heap sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, y);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
