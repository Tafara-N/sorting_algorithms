#include "sort.h"

void swapping_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - Ordering a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: Array of integers
 * @size: Array size
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 *
 * Return: Final partitioned index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, top, bottom;

	pivot = array + right;
	for (top = bottom = left; bottom < right; bottom++)
	{
		if (array[bottom] < *pivot)
		{
			if (top < bottom)
			{
				swapping_ints(array + bottom, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *pivot)
	{
		swapping_ints(array + top, pivot);
		print_array(array, size);
	}

	return (top);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: Array of integers to sort
 * @size: Array size
 * @left: Starting index of the array partition to order
 * @right: Ending index of the array partition to order
 *
 * Description: Using the Lomuto partitioning scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int piece;

	if (right - left > 0)
	{
		piece = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, piece - 1);
		lomuto_sort(array, size, piece + 1, right);
	}
}

/**
 * quick_sort - Sorting an array of integers in ascending
 *              order using the Quick Sort Algorithm
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Using the Lomuto partitioning scheme. Printing
 *              the array after every swap of two elements
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}