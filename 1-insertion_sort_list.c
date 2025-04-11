#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 *
 * @list: Pointer to the head of the list
 * @node1: The first node to swap (must be before node2)
 * @node2: The second node to swap (must be after node1)
 *
 * Description: This function swaps node1 and node2 in the list
 * by updating their prev and next pointers.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	/* Si node1 n'est pas au début de la liste relier son précédent à node2 */
	if (node1->prev != NULL)
		node1->prev->next = node2;

	else
		*list = node2; /* Sinon, node2 devient le nouveau head */

	/* Si node2 n'est pas à la fin, relier son suivant à node1 */
	if (node2->next != NULL)
		node2->next->prev = node1;

	/* Mise à jour des pointeurs pour échanger node1 et node2 */
	node2->prev = node1->prev;
	node1->next = node2->next;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the list
 *
 * Description: This function sorts a doubly linked list by iterating
 * through the list and swapping nodes backwards until they are in order.
 * The list is printed after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *next;

	/* Vérifie que la liste est valide et contient au moins 2 éléments */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Commence le tri à partir du deuxième élément */
	current = (*list)->next;

	/* Parcours de la liste jusqu'à la fin */
	while (current != NULL)
	{
		/* Sauvegarde du node suivant avant un éventuel déplacement */
		next = current->next;

		/* Tant que l'élément courant est plus petit que celui avant lui */
		while (current->prev != NULL && current->n < current->prev->n)
		{
			/* On échange current avec son précédent */
			swap_nodes(list, current->prev, current);
			/* Affiche la liste après chaque échange */
			print_list(*list);
		}
		/* Passe au node suivant */
		current = next;
	}
}
