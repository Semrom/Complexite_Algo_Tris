#include "insertion_dichotomique.h"

int position_dicho(int i, int t[]) {

/* Spécification externes :
 *	Calcul de la position d'insertion p de manière dichotomique.
 */

	 int gauche = 0;
	 int droite = i;
	 int milieu;

	 while(gauche < droite) {
		milieu = (droite + gauche) / 2;
		if (t[milieu] < t[i]) {
			gauche = milieu + 1;
		} else {
			droite = milieu;
		}
	 }

	 return gauche;
}

void tri_insertion_dichotomique(int tableau[], int taille) {

/* Spécifications externes :
 *   tri du tableau "tableau" par insertion séquentielle.
 */

	 int i, p, x;

	 for (i = 1; i < taille; i = i + 1) {
		 p = position_dicho(i, tableau);
		 x = tableau[i];
		 translation(p, i, tableau);
		 tableau[p] = x;
	 }

}
