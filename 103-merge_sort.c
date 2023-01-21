#include "sort.h"

void my_merge_sort(int *array, int start, int end);
void merge(int *array, int start, int mid, int end);

void merge_sort(int *array, size_t size)
{
	my_merge_sort(array, 0, size - 1);
}

void my_merge_sort(int *array, int start, int end)
{

	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;

		my_merge_sort(array, start, mid);
		my_merge_sort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}

void merge(int *array, int start, int mid, int end)
{
	int leftArray[4096];
	int rightArray[4096];
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	int i = 0, j = 0, k = start;

	/* populate left array */
	for (i = 0; i < leftSize; i++)
	{
		leftArray[i] = array[i + start];
	}
	/* populate right array */
	for (i = 0; i < rightSize; i++)
	{
		rightArray[i] = array[i + mid + 1];
	}

	i = 0, j = 0, k = start;

	while (i < leftSize && j < rightSize)
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			k++;
			i++;
		}
		if (leftArray[i] > rightArray[j])
		{
			array[k] = rightArray[j];
			k++;
			j++;
		}
	}
	while (i < leftSize)
	{
		array[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < rightSize)
	{
		array[k] = rightArray[j];
		j++;
		k++;
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(leftArray, leftSize);
	printf("[right]: ");
	print_array(rightArray, rightSize);
	printf("[Done]: ");
	print_array(array, leftSize + rightSize);
}
