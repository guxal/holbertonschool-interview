#include "sort.h"

/**
 * merge - merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @m: Middle index
 * @tmp: Temp array
 * Return: Nothing.
 */
void merge(int *array, int size, int m, int *tmp)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, m);
	printf("[right]: ");
	print_array(array + m, size - m);

	for (i = 0, j = m, k = 0; k < size; k++)
	{
		if (j == size)
		{
			tmp[k] = array[i];
			i++;
		}
		else if (i == m)
		{
			tmp[k] = array[j];
			j++;
		}
		else if (array[j] < array[i])
		{
			tmp[k] = array[j];
			j++;
		}
		else
		{
			tmp[k] = array[i];
			i++;
		}
	}
	for (i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}

	printf("[Done]: ");
	print_array(tmp, size);
}

/**
 * merge_main - merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @tmp: Temp array
 * Return: Nothing.
 */
void merge_main(int *array, size_t size, int *tmp)
{
	int m;

	if (size < 2)
		return;
	m = size / 2;
	merge_main(array, m, tmp);
	merge_main(array + m, size - m, tmp);
	merge(array, size, m, tmp);
}

/**
 * merge_sort - merge sort
 * @array: Array to be sorted
 * @size: Size of the array
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);

	if (!tmp)
		return;

	merge_main(array, size, tmp);
	free(tmp);
}
