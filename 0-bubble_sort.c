#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 *
 * @array: The array of integers to sort
 * @size: The size of the array
 *
 * Description: Goes through the array repeatedly, compares
 * adjacent elements and swaps them if they are in the wrong order.
 * Prints the array after each swap.
 */


void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
