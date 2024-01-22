#include "sort.h"

/**
 * swapping_ints - Swapping two integers in an array
 * @a: First integer to be swapped
 * @b: Second integer to be swapped
 */

void swapping_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sorting an array of integers in ascending
 *              order using the Shell Sort Algorithm.
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Using the Knuth interval sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t space, x, y;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (x = space; x < size; x++)
		{
			y = x;
			while (y >= space && array[y - space] > array[y])
			{
				swapping_ints(array + y, array + (y - space));
				y -= space;
			}
		}
		print_array(array, size);
	}
}