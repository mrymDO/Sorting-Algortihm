#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	merge_sort_recursion(array, temp, 0, size - 1);

	free(temp);
}
/**
 * merge_sort_recursion - merges sorted arrays recursively
 * @array: array to be sorted
 * @temp: temporory array used for merging
 * @l: index of left element
 * @r: index of right element
 */
void merge_sort_recursion(int *array, int *temp, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;

		merge_sort_recursion(array, temp, l, m);
		merge_sort_recursion(array, temp, m + 1, r);

		merge_sorted_arrays(array, temp, l, m, r);
	}
}
/**
 * merge_sorted_arrays - merge the subarrays
 * @array: array to be sorted
 * @temp: temporory array used for merging
 * @l: index of left element of array
 * @r: index of right elemet of array
 * @m: index of  middle element of array
 */
void merge_sorted_arrays(int *array, int *temp, int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + l, m - l + 1);
	printf("[right]: ");
	print_array(array + m + 1, r - m);

	while (i <= m && j <= r)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= m)
		temp[k++] = array[i++];

	while (j <= r)
		temp[k++] = array[j++];

	for (k = l; k <= r; k++)
		array[k] = temp[k];

	printf("[Done]: ");
	print_array(array + l, r - l + 1);
}
