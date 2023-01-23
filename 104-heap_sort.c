#include "sort.h"


void maxHeapify(int array[], int size, int index, int maxsize);

/**
 * heap_sort - sorts an array of
 * integers in ascending order using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int maxsize;

	int temp __attribute__((unused));

	maxsize = size;
	for (i = size / 2 - 1; i >= 0; i--)
		maxHeapify(array, size, i, maxsize);

	for (i = size - 1; i > 0; i--)
	{
		/*swap last element with first element*/
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;

		print_array(array, maxsize);

		maxHeapify(array, i, 0, maxsize);

	}
}

/**
 * maxHeapify - makes sure the node we are pointing to
 * satistfies the conditions of a maximum heap
 * @array: array to heapify
 * @size: size of the heap (this will reduce as we a
 * heap and a sorted section of the array)
 * @index: index to heapify from
 * @maxsize: total size of the array
 *	(size of heap section + size of sorted part of the array)
 */
void maxHeapify(int array[], int size, int index, int maxsize)
{
	int temp __attribute__((unused)) = 0;
	int lIndex = index * 2 + 1;
	int rIndex = index * 2 + 2;
	int largest = index;

	if (lIndex < size && array[lIndex] > array[largest])
		largest = lIndex;
	if (rIndex < size && array[rIndex] > array[largest])
		largest = rIndex;

	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;

		print_array(array, maxsize);

		maxHeapify(array, size, largest, maxsize);
	}
}
