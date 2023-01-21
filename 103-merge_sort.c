#include "sort.h"
void merge(int *leftArr, int leftSize, int *rightArr,
		   int rightSize, int *array);
/**
 * merge_sort - merge sort algorithm
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{

	size_t mid = size / 2;
	size_t i = 0;
	int leftSize = mid;
	int rightSize = size - mid;
	int leftArr[4096];
	int rightArr[4096];

	if (size < 2)
		return;

	for (i = 0; i < mid; i++)
	{
		leftArr[i] = array[i];
	}
	for (i = mid; i < size; i++)
	{
		rightArr[i - mid] = array[i];
	}

	merge_sort(leftArr, leftSize);
	merge_sort(rightArr, rightSize);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(leftArr, leftSize);
	printf("[right]: ");
	print_array(rightArr, rightSize);
	merge(leftArr, leftSize, rightArr, rightSize, array);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - merge function in merge_sort
 * @leftArr: left array
 * @leftSize: size of left array
 * @rightArr: right array
 * @rightSize: size of right array
 * @array: array to merge in place
 */
void merge(int *leftArr, int leftSize, int *rightArr,
		   int rightSize, int *array)
{
	int i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i] <= rightArr[j])
		{
			array[k] = leftArr[i];
			i++;
			k++;
		}
		else
		{
			array[k] = rightArr[j];
			k++;
			j++;
		}
	}
	while (i < leftSize)
	{
		array[k] = leftArr[i];
		k++;
		i++;
	}
	while (j < rightSize)
	{
		array[k] = rightArr[j];
		k++;
		j++;
	}
}
