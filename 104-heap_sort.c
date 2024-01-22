#include "sort.h"

void swapping_ints(int *a, int *b);
void maximum_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * maximum_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: Array or tree size
 * @base: Index of the base row of the tree
 * @root: Root node of the binary tree
 */

void maximum_heapify(int *array, size_t size, size_t base, size_t root)
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
		swapping_ints(array + root, array + large);
		print_array(array, size);
		maximum_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorting an array of integers in ascending
 *             order using the Heap Sort algorithm.
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Implementing the sift down heap sort
 * algorithm.
 * Printing the array after every swap
 */

void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		maximum_heapify(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swapping_ints(array, array + x);
		print_array(array, size);
		maximum_heapify(array, size, x, 0);
	}
}
