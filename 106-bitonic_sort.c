#include "sort.h"

void swap(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap - Swaps two ints in an array.
 * @x: First int to be swaped.
 * @y: Second int to be swaped.
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bitonic_merge - Sorts bitonic sequence inside an array of ints.
 * @array: Array of ints.
 * @size: Size of the array.
 * @start: Starting index of the sequence in array to sort.
 * @seq: Size of the sequence to sort.
 * @flow: Ddirection to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t s, jump = seq / 2;

	if (seq > 1)
	{
		for (s = start; s < start + jump; s++)
		{
			if ((flow == UP && array[s] > array[s + jump]) ||
			    (flow == DOWN && array[s] < array[s + jump]))
				swap(array + s, array + s + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert array of ints into a bitonic sequence.
 * @array: Array of ints.
 * @size: Size of the array.
 * @start: Starting index of a block of the building bitonic sequence.
 * @seq: Size of a block of the building bitonic sequence.
 * @flow: Direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts array of ints in ascending
 *                order using the bitonic sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
