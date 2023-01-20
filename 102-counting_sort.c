#include "sort.h"


/**
 * counting_sort - sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	size_t max;
	int *c_arr;
	int *sort_arr;
	int cum = 0;

	if (array == NULL)
		return;
	if (size == 1 || size == 0)
		return;
	max = array[0];
	for (i = 1; i < size; i++) /*find max munber*/
		if ((size_t)array[i] > max)
			max = array[i];

	c_arr = malloc(sizeof(int) * (max + 1));
	for (i = 0; i < max + 1; i++) /*fill with 0*/
		c_arr[i] = 0;

	for (i = 0; i < size; i++)/*count the freq of items in array*/
		c_arr[array[i]] += 1;

	for (i = 0; i < max + 1; i++)/*calc the cummulative freq*/
		c_arr[i] += cum, cum = c_arr[i];

	print_array(c_arr, max + 1);

	sort_arr = malloc(sizeof(int) * cum);
	for (i = 0; i < size; i++)
	{
		sort_arr[c_arr[array[i]] - 1] = array[i];
		c_arr[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = sort_arr[i];
	free(c_arr);
	free(sort_arr);
}
