#include "sort.h"

void sort_bitonic(int array[],
		int lowIndex, int count, int maxszie, int direction);
void bitonic_merge(int *array,
		int lowIndex, int count, int direction);
/**
 * bitonic_sort - sorts an array of
 * integers in ascending order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	sort_bitonic(array, 0, size, size, 1);
}


/**
 * sort_bitonic - sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @lowIndex: the lowest index of the
 * array -or subarray- that we are working with
 * @count: the number of elements in the
 * array -or subarray- that we are working with
 * @maxsize: maximum size of the array
 * @direction: determines if we are to
 * sort the list in ascending or descending order:
 *	1: sort in ascending order
 *	0: sort in descending order
 */
void sort_bitonic(int array[], int lowIndex,
		int count, int maxsize, int direction)
{
	int k;

	if (count == 1)
		return;

	k = count / 2;

	printf("Merging [%d/%d] (%s):\n", count, maxsize, direction ? "UP" : "DOWN");
	print_array(array + lowIndex, count);

	sort_bitonic(array, lowIndex, k, maxsize, 1);
	sort_bitonic(array, lowIndex + k, k, maxsize, 0);

	bitonic_merge(array, lowIndex, count, direction);

	printf("Result [%d/%d] (%s):\n", count, maxsize, direction ? "UP" : "DOWN");
	print_array(array + lowIndex, count);
}


/**
 * bitonic_merge - merge two bitonic sequences
 * @array: array to be sorted
 * @lowIndex: the lowest index of the array
 * -or subarray- that we are working with
 * @count: the number of elements in the array
 * -or subarray- that we are working with
 * @direction: determines if we are to sort the
 * list in ascending or descending order:
 *	1: sort in ascending order
 *	0: sort in descending order
 */
void bitonic_merge(int *array, int lowIndex, int count, int direction)
{
	int k, i, temp;

	if (count == 1)
		return;

	k = count / 2;
	for (i = lowIndex; i < lowIndex + k; i++)
	{
		if (direction == (array[i] > array[i + k]))
		{
			temp = array[i];
			array[i] = array[i + k];
			array[i + k] = temp;
		}
	}

	bitonic_merge(array, lowIndex, k, direction);
	bitonic_merge(array, lowIndex + k, k, direction);
}
