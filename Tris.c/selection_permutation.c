#include "selection_permutation.h"

void tri_selection_permutation(int tableau[], int taille)

/*
 *	Spécifications externes :
 *	  Calcule le minimum sur tableau[0...MAX-1] puis le permute avec l'indice actuel.
 *	- Entrée : Le tableau à trier.
 *	- Sortie : Le tableau tiré dans l'ordre croissant.
 */

{
	int i, min, j;
	i = 0;

	while (i < taille - 1) {

		/* CALCUL DU MIN SUR tableau[i...n - 1] */

		min = i;
		j = i + 1;

		while (j < taille) {
			if (tableau[j] < tableau[min]) {
				min = j;
			}

			j = j + 1;
		}

		permute(i, min, tableau);
		i = i + 1;
	}
}
