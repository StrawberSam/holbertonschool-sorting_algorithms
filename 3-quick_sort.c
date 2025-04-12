#include "sort.h"

/**
 * partition - Partitions the array using Lomuto scheme
 * @array: Array to partition
 * @start: Starting index of the sub-array
 * @end: Ending index of the sub-array (pivot)
 * @size: Size of the array (for print_array)
 *
 * Return: Index of the pivot after partition
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot;
	int tmp;
	int i;
	int j;

	i = start - 1;
	pivot = array[end]; /* Le pivot est toujours le dernier élément */

	/* Parcours du sous-tableau */
	for (j = start; j < end; j++)
	{
		/* Si l'élément courant est plus petit ou égal au pivot */
		if (array[j] <= pivot)
		{
			i++; /* On déplace la frontière des petits éléments */

			/* On échange array[i] et array[j] si nécessaire */
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size); /* Affichage après chaque swap */
			}

		}
	}

	/* On place le pivot à sa position finale */
	if (i + 1 != end)
	{
		tmp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}

	return (i + 1); /* Retourne la position du pivot */
}

/**
 * quick_sort_recursive - Recursively sorts sub-arrays using Quick sort
 * @array: Array to sort
 * @start: Starting index of the sub-array
 * @end: Ending index of the sub-array
 * @size: Size of the array (for print_array)
 *
 * Return: Nothing
 */
void quick_sort_recursive(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		/* Partitionne le tableau et récupère l'index du pivot */
		pivot_index = partition(array, start, end, size);

		/* Trie récursivement la partie gauche */
		quick_sort_recursive(array, start, pivot_index - 1, size);

		/* Trie récursivement la partie droite */
		quick_sort_recursive(array, pivot_index + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

