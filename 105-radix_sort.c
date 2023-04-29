#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get maximum value in array of ints.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Return: Maximum int in the array.
 */
int get_max(int *array, int size)
{
	int max, m;

	for (max = array[0], m = 1; m < size; m++)
	{
		if (array[i] > max)
			max = array[m];
	}

	return (max);
}

/**
 * radix_counting_sort - Sorts the significant digits of array of ints
 *                       in ascending order using the counting sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 * @sig: Significant digit to sort on.
 * @buff: Buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t s;

	for (s = 0; s < size; s++)
		count[(array[s] / sig) % 10] += 1;

	for (s = 0; s < 10; s++)
		count[s] += count[s - 1];

	for (s = size - 1; (int)s >= 0; s--)
	{
		buff[count[(array[s] / sig) % 10] - 1] = array[s];
		count[(array[s] / sig) % 10] -= 1;
	}

	for (s = 0; s < size; s++)
		array[s] = buff[s];
}

/**
 * radix_sort - Sorts an array ints in ascending
 *              order using the radix sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
