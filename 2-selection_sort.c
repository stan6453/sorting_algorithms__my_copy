#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex, temp;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;

		}
		if (minIndex != i)
		{
			temp = array[minIndex];
			array[minIndex] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
