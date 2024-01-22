#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buffer);
void radix_sort(int *array, size_t size);

/**
 * get_max - Gets the maximum value in an array of integers
 * @array: Array of integers
 * @size: Array size
 *
 * Return: Maximum integer in the array
 */

int get_max(int *array, int size)
{
	int maximum, x;

	for (maximum = array[0], x = 1; x < size; x++)
	{
		if (array[x] > maximum)
			maximum = array[x];
	}

	return (maximum);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t x;

	for (x = 0; x < size; x++)
		count[(array[x] / sig) % 10] += 1;

	for (x = 0; x < 10; x++)
		count[x] += count[x - 1];

	for (x = size - 1; (int)x >= 0; x--)
	{
		buffer[count[(array[x] / sig) % 10] - 1] = array[x];
		count[(array[x] / sig) % 10] -= 1;
	}

	for (x = 0; x < size; x++)
		array[x] = buffer[x];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the Radix sort algorithm.
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Implementing the LSD radix sort algorithm. Prints
 * the array after each significant digit increase
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buffer);
		print_array(array, size);
	}

	free(buffer);
}
