#include "sort.h"

void my_quick_sort(int *array, int start, int end, size_t whole_size);
int partition(int *array, int start, int end, size_t whole_size);

/**
 * quick_sort_hoare - quick sort
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (size < 2)
		return;

	my_quick_sort(array, start, end, size);
}

/**
 * my_quick_sort - quick sort implementation
 * @array: array
 * @start: start
 * @end: end
 * @whole_size: size of array
 *
 * Return: void
 */
void my_quick_sort(int *array, int start, int end, size_t whole_size)
{
	if (start < end)
	{
		int partition_index = partition(array, start, end, whole_size);

		my_quick_sort(array, start, partition_index - 1, whole_size);

		my_quick_sort(array, partition_index + 1, end, whole_size);
	}
}

/**
 * partition - hoare's partition
 * @array: array
 * @start: start
 * @end: end
 * @whole_size: whole size
 *
 * Return: partition index
 */
int partition(int *array, int start, int end, size_t whole_size)
{
	int temp = 0;
	int pivot, pivot_index;

	if (array[start] > array[end])
	{
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;

		print_array(array, whole_size);
	}

	pivot = array[start];
	pivot_index = start;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;

		if (start < end)
		{
			if (array[start] != array[end])
			{
				temp = array[start];
				array[start] = array[end];
				array[end] = temp;
				print_array(array, whole_size);
			}
		}
	}

	if (array[end] != array[pivot_index])
	{
		temp = array[end];
		array[end] = array[pivot_index];
		array[pivot_index] = temp;
		print_array(array, whole_size);
	}

	return (end);
}
