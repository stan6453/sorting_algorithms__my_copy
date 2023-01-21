#include "sort.h"


void sort_bitonic(int array[], int lowIndex, int count, int direction);
void bitonic_merge(int *array, int lowIndex, int count, int direction);
/**
 * bitonic_sort - sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	sort_bitonic(array, 0, size, 1);
}


/**
 * sort_bitonic - sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @lowIndex: the lowest index of the array -or subarray- that we are working with
 * @count: the number of elements in the array -or subarray- that we are working with
 * @direction: determines if we are to sort the list in ascending or descending order:
 *	1: sort in ascending order
 *	0: sort in descending order
 */
void sort_bitonic(int array[], int lowIndex, int count, int direction)
{
	int k;

	if (count == 1)
		return;
	
	k = count / 2;
	sort_bitonic(array, lowIndex, k, 1);
	sort_bitonic(array, lowIndex + k, k, 0);

	
	bitonic_merge(array, lowIndex, count, direction);

}


/**
 * bitonic_merge - merge two bitonic sequences
 * @array: array to be sorted
 * @lowIndex: the lowest index of the array -or subarray- that we are working with
 * @count: the number of elements in the array -or subarray- that we are working with
 * @direction: determines if we are to sort the list in ascending or descending order:
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

			printf("Merging [%d/%d] %d:\n", k, count, direction);
			print_array(array, count);
		}
	}

	bitonic_merge(array, lowIndex, k, direction);
	bitonic_merge(array, lowIndex + k, k, direction);
}
