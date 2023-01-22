#include "sort.h"

/**
 * my_counting_sort - sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @arr: array to be sorted
 * @n: size of the array
 * @exp: exponent to sort by
 */
void my_counting_sort(int arr[], int n, int exp)
{
	int max = arr[0], i = 0;
	int *output = malloc(sizeof(int) * n); /* output array */
	int *count;

	/* get the max value in the array */
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (!count || !output)
		exit(0);
	/* populate count array with zeros */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Store count of occurrences in count[] at LSD */
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	/* change count to hold cumulative at the positions */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	/**
	 * Copy the output array to arr[], so that arr[] now
	 * contains sorted numbers according to current digit
	 */
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
	free(count);
}

/**
 * radix_sort - radix sort algorithm
 * @array: whole array
 * @size: size of array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, i, exponent;

	if (size < 2)
		return;

	max = array[0], i = 0, exponent = 1;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] >= max)
			max = array[i];
	}

	for (exponent = 1; (max / exponent) > 0; exponent *= 10)
	{
		my_counting_sort(array, size, exponent);
		print_array(array, size);
	}
}
