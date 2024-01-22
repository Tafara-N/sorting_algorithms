#include "sort.h"

/**
 * get_max - Gets the maximum value in an array of integers
 * @array: Array of integers
 * @size: Array size
 *
 * Return: The maximum integer in the array.
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
 * counting_sort - Sorting an array of integers in ascending order
 *                 using the Counting Sort algorithm.
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maximum, x;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_max(array, size);
	count = malloc(sizeof(int) * (maximum + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (x = 0; x < (maximum + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 0; x < (maximum + 1); x++)
		count[x] += count[x - 1];
	print_array(count, maximum + 1);

	for (x = 0; x < (int)size; x++)
	{
		sorted[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sorted[x];

	free(sorted);
	free(count);
}
