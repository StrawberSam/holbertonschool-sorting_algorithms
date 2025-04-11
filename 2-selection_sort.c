#include "sort.h"

/**
 * selection_sort - Trie un tableau d'entiers en utilisant
 * l'algo de tri par sélection
 * @array: Tableau à trier
 * @size: Taille du tableau
 *
 * Description : L'algorithme trie le tableau en cherchant l'élément le
 * plus petit à chaque passage et en l'échangeant avec l'élément actuel.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index = 0, temp;

/* Vérifier si tableau est valide et si taille est suffisante pour le tri */
	if (!array || size < 2)
		return;

/* Boucle principale : parcourir tout le tableau sauf le dernier élément */
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;/* Initialiser min_index à la position actuelle (i) */

		/* Boucle interne : comparer l'élément actuel avec les suivants */
		for (j = i + 1; j < size; j++)
		{
			/* Si l'élément à j est plus petit que l'élément à min_index */
			if (array[j] < array[min_index])
			{
				min_index = j;/* Mettre à jour min_index */
			}
		}

/*Si min_index a changé cela signifie que élément le+ petit n'est pas à i*/
		if (min_index != i)
		{
			temp = array[i];/*on échange les éléments*/
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
