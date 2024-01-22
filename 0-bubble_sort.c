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
 * bubble_sort - Sorting an array of integers in ascending order
 * @array: Array of integers to be sorted
 * @size: Array size
 *
 * Description: Printing the array after every swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, length = size;
	Boolean bubbly = False;

	if (array == NULL || size < 2)
		return;

	while (bubbly == False)
	{
		bubbly = True;
		for (x = 0; x < length - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swapping_ints(array + x, array + x + 1);
				print_array(array, size);
				bubbly = False;
			}
		}
		length--;
	}
}
