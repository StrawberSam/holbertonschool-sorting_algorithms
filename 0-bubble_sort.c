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

	/* Boucle qui effectue plusieurs passages dans le tableau */
	for (i = 0; i < size - 1; i++)
	{
		/*
		 * À chaque passage, on compare les éléments adjacents.
		 * On s'arrête à size - i - 1 car les plus grands éléments
		 * sont déjà triés et placés à la fin du tableau.
		 */
		for (j = 0; j < size - i - 1; j++)
		{
			/* Si l'élément courant est plus grand que le suivant */
			if (array[j] > array[j + 1])
			{
				/* On échange les deux éléments */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* On affiche le tableau après chaque échange */
				print_array(array, size);
			}
		}
	}
}
