#include "sort.h"

void merging_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merging_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merging_subarr - Sorting a subarray of integers
 * @subarr: A subarray of an array of integers to be sorted
 * @buff: Buffer to store the sorted subarray
 * @front: Front index of the array
 * @mid: Middle index of the array
 * @back: Back index of the array
 */

void merging_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t j, x, y = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (j = front, x = mid; j < mid && x < back; y++)
		buff[y] = (subarr[j] < subarr[x]) ? subarr[x++] : subarr[y++];
	for (; j < mid; j++)
		buff[y++] = subarr[j];
	for (; x < back; x++)
		buff[y++] = subarr[x];
	for (j = front, y = 0; j < back; j++)
		subarr[j] = buff[y++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merging_sort_recursive - Implementing the Merge sort algorithm
 *						through recursion
 * @subarr: Subarray of an array of integers to sort.
 * @buff: Buffer to store the sorted result.
 * @front: Front index of the subarray.
 * @back: Back index of the subarray.
 */

void merging_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merging_sort_recursive(subarr, buff, front, mid);
		merging_sort_recursive(subarr, buff, mid, back);
		merging_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using Merge sort algorithm
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merging_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
