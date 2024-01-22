#include "sort.h"

void swapping_ints(int *a, int *b);
int hoare_partitioning(int *array, size_t size, int left, int right);
void hoare_sorting(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partitioning - Order a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: Array of integers
 * @size: Array size
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 *
 * Return: Final partitioned index
 *
 * Description: Using the last element of the partition as the pivot.
 * Prints the array after every swap of two elements
 */

int hoare_partitioning(int *array, size_t size, int left, int right)
{
	int pivot, top, bottom;

	pivot = array[right];
	for (top = left - 1, bottom = right + 1; top < bottom;)
	{
		do {
			top++;
		} while (array[top] < pivot);
		do {
			bottom--;
		} while (array[bottom] > pivot);

		if (top < bottom)
		{
			swapping_ints(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sorting - Implementing the Quick sort algorithm through recursion
 * @array: Array of integers to be sorted
 * @size: Array size
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: Using the Hoare partitioning scheme
 */

void hoare_sorting(int *array, size_t size, int left, int right)
{
	int piece;

	if (right - left > 0)
	{
		piece = hoare_partitioning(array, size, left, right);
		hoare_sorting(array, size, left, piece - 1);
		hoare_sorting(array, size, piece, right);
	}
}

/**
 * quick_sort_hoare - Sorting an array of integers in ascending
 *                    order using the Quick sort algorithm
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Using the Hoare partitioning scheme
 * Printing the array after every swap of two elements
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sorting(array, size, 0, size - 1);
}
