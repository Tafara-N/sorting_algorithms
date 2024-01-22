#include "sort.h"

void swapping_ints(int *a, int *b);
void bitonic_merging(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
											char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swapping_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */

void swapping_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merging - Sort a bitonic sequence inside an array of integers.
 * @array: Array of integers
 * @size: Array size
 * @start: Starting index of the sequence in array to be sorted
 * @seq: Size of the sequence to be sorted
 * @flow: Direction to sort in
 */

void bitonic_merging(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t x, jump = seq / 2;

	if (seq > 1)
	{
		for (x = start; x < start + jump; x++)
		{
			if ((flow == UP && array[x] > array[x + jump]) ||
			    (flow == DOWN && array[x] < array[x + jump]))
				swapping_ints(array + x, array + x + jump);
		}
		bitonic_merging(array, size, start, jump, flow);
		bitonic_merging(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sequence - Converting an array of integers to a bitonic sequence
 * @array: Array of integers
 * @size: Array size
 * @start: Starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */

void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
												char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_sequence(array, size, start, cut, UP);
		bitonic_sequence(array, size, start + cut, cut, DOWN);
		bitonic_merging(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorting an array of integers in ascending
 *                order using the Bitonic sort algorithm
 * @array: Array of integers
 * @size: Array size
 *
 * Description: Printing the array after every swap.
 * Only works for size = 2^k where k >= 0
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
