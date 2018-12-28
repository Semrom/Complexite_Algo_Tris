#include "insertion_sequentielle.h"

int position(int i, int t[]) {

	/* Spécification externes :
	 * Calcul de la position d'insertion p :
	 * détermine le plus petit indice
	 * p / 0 <= p <= i qui vérifie t[p] >= t[i]
	 */

	 int p;
	 p = 0;
	 while(t[p] < t[i])
		p = p + 1;

	 return p;
}

void tri_insertion_seq(int tableau[], int taille) {

	/* Spécifications externes :
	 * tri du tableau "tableau" par insertion séquentielle.
	 */

	 int i, p, x;

	 for (i = 1; i < taille; i = i + 1) {
		 p = position(i, tableau);
		 x = tableau[i];
		 translation(p, i, tableau);
		 tableau[p] = x;
	 }

}
