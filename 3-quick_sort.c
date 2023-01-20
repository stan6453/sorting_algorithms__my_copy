#include "sort.h"

void my_quick_sort(int *array, int start, int end, int whole_size);

/**
 * partition - lomuto partition scheme
 * @array: array to sort
 * @start: start of array
 * @end: end of array
 * @whole_size: size of whole array
 *
 * Return: pivot location
 */
int partition(int *array, int start, int end, int whole_size)
{
	int partition = start - 1;
	int pivot = array[end];
	int i = 0, temp;

	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			partition++;
			if (array[i] != array[partition])
			{
				temp = array[i];
				array[i] = array[partition];
				array[partition] = temp;
				print_array(array, whole_size);
			}
		}
	}
	if (array[partition + 1] != array[end])
	{
		temp = array[partition + 1];
		array[partition + 1] = array[end];
		array[end] = temp;
		print_array(array, whole_size);
	}

	return (partition + 1);
}

/**
 * quick_sort - quick_sort skeleton
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;

	if (size <= 1 || array == NULL)
		return;

	my_quick_sort(array, start, end, size);
}

/**
 * my_quick_sort - quick sort implementation
 * @array: array
 * @start: start of array
 * @end: end of array
 * @whole_size: size of array
 *
 * Return: void
 */
void my_quick_sort(int *array, int start, int end, int whole_size)
{
	if (start < end)
	{
		int partition_index = partition(array, start, end, whole_size);

		my_quick_sort(array, start, partition_index - 1, whole_size);
		my_quick_sort(array, partition_index + 1, end, whole_size);
	}
}
