#include "bulles.h"

void tri_a_bulles(int tableau[], int taille) {

/*
*	Spécifications externes :
*	  Compare les éléments deux à deux et les permute si l'un est plus petit que l'autre.
*	- Entrée : Le tableau à trier.
*	- Sortie : Le tableau tiré dans l'ordre croissant.
*/

	int i, j;
	i = 0;
	while (i < taille - 1) {
		j = taille - 1;
		while (j > i) {
			if (tableau[j] < tableau[j - 1])
				permute(j, j - 1, tableau);
			j = j - 1;
		}

		i = i + 1;
	}

}
