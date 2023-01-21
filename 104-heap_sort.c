#include "sort.h"


/**
 * heap_sort - sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp, pindex, lchild, rchild,  bindex, compchild;
	/*size_t realSize = size;*/

	for (i = size - 1; i >= 0; i--)
	{

		if ((size_t)(i * 2 + 1) > size)/*if node deos not have a child  within our heap, skip*/
			continue;

		pindex = i;
		lchild = i * 2 + 1;
		rchild = i * 2 + 2;/*beore uisng, chech is it points outside the Size*/

		while (array[pindex] < array[lchild] || array[pindex] < array[rchild])
		{
			if (array[pindex] < array[lchild])
			{
				bindex = pindex;
				compchild = lchild;
				while(bindex >= 0 && array[bindex] < array[compchild])
				{
					temp = array[bindex];
					array[bindex] = array[compchild];
					array[compchild] = temp;
					compchild = bindex;
					if (bindex % 2)
						bindex = bindex / 2;
					else
						bindex = (bindex / 2) - 1;
				}
			}
			else if ((size_t)rchild <= size && array[pindex] < array[rchild])
			{
				bindex = pindex;
				compchild = rchild;
				while(bindex >= 0 && array[bindex] < array[compchild])
				{
					temp = array[bindex];
					array[bindex] = array[compchild];
					array[compchild] = temp;
					compchild = bindex;
					if (bindex % 2)
						bindex = bindex / 2;
					else
						bindex = (bindex / 2) - 1;
				}
			}
			printf("somewhere inbetween:");
			print_array(array, size);
		}
	}
}
