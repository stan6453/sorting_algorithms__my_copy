#include "sort.h"

void my_quick_sort(int *array, int start, int end, size_t whole_size);
int partition(int *array, int start, int end, size_t whole_size);
void swap(int *a, int *b);

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

		my_quick_sort(array, start, partition_index, whole_size);

		my_quick_sort(array, partition_index + 1, end, whole_size);
	}
}

/**
 * partition - hoare's partition
 * @array: array
 * @low: start
 * @high: end
 * @whole_size: whole size
 *
 * Return: partition index
 */
int partition(int *array, int low, int high, size_t whole_size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i > j)
		{
			return (j);
		}
		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, whole_size);
		}
	}
}

/**
 * swap - swap values
 * @a: value a
 * @b: value b
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
