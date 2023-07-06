#include "sort.h"

/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sort(array, 0, size - 1, size);
}

/**
 * sort - sort subarrays recursively
 * @array: pointer to array to be sorted;
 * @low: starting index to the subarray to be sorted
 * @high: ending index of subarray to be sorted
 * @size: size of array
 */

void sort(int *array, int low, int high, size_t size)
{
	int partition_i;

	if (low < high)
	{
		partition_i = partition(array, low, high, size);
		sort(array, low, partition_i - 1, size);
		sort(array, partition_i + 1, high, size);
	}
}

/**
 * partition - partitioning elements into two sub-arrays
 * according they are less or greater than the pivot
 * @array: pointer to array that need to be partitioned
 * @low: starting index of subarray to be partitioned
 * @high: ending index of subarray to be partitioned
 * @size: size of array
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] < array[i])
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - swap two integer
 * @a: 1st integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
