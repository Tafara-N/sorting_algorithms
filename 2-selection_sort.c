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
 * selection_sort - Sorting an array of integers in ascending order
 *                  using the Selection Sort Algorithm
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Printing an array after every swap
 */

void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		minimum = array + x;
		for (y = x + 1; y < size; y++)
			minimum = (array[y] < *minimum) ? (array + y) : minimum;

		if ((array + x) != minimum)
		{
			swapping_ints(array + x, minimum);
			print_array(array, size);
		}
	}
}
