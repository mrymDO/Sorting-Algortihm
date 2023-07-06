#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t j, gap = 1;
	int i;

	if (size < 2)
		return;

	for (gap = 1; gap <= size / 3; gap = gap * 3 + 1)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] > array[i])
					break;

				swap(&array[i + gap], &array[i]);

			}
		}
		print_array(array, size);
	}
}
/**
 * swap - swap two elements
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
