#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *	You must use the following
 *	sequence of intervals (a.k.a the Knuth sequence):
 *	n+1 = n * 3 + 1
 *	1, 4, 13, 40, 121, ...
 * @array: array to be sorted
 * @size: size of the array
 * Return: 0 if program exited without errors
 */
void shell_sort(int *array, size_t size)
{
	size_t j, gap;
	int temp, bIndex;

	if (array == NULL)
		return;
	if (size == 1 || size == 0)
		return;
	gap = 1;
	while (gap <=  (size / 3))
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		bIndex = gap;
		j = bIndex;
		while (j < size)
		{
			while ((int) (bIndex - gap) >= 0 && array[bIndex] < array[bIndex - gap])
			{
				temp = array[bIndex];
				array[bIndex] = array[bIndex - gap];
				array[bIndex - gap] = temp;
				bIndex -= gap;
			}
			bIndex = j + 1;
			j = bIndex;
		}
		gap = (int)((gap - 1) / 3);
		print_array(array, size);
		j = 0;
	}

}
