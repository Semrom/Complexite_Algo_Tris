#include "rapide.h"

void placer_pivot(int gauche, int droite, int t[], int *position) {

/*
*	Spécifications externes :
*	- Entrée : Deux indices du tableau, 0 <= g < d <= MAX-1 et x = t[g].
*	- Sortie : p déterminé et t[g...d] est réorganisé de telle façon que x = t[p], t[g...p-1] <= x, x <= t[p+1...d].
*/

	*position = gauche;
	int pivot = t[gauche];
	int i;

	for (i = gauche + 1; i <= droite; i++) {
		if (t[i] < pivot) {
			(*position)++;

			if (i != *position)
				permute(i, *position, t);
		}
	}

	permute(*position, gauche, t);
}

void tri_rapide_init(int gauche, int droite, int t[]) {

/*
*	Spécifications externes :
*		Réalise le tri de t[g...d]
*/

	int position;

	if (gauche < droite) {
		placer_pivot(gauche, droite, t, &position);
		tri_rapide_init(gauche, position - 1, t);
		tri_rapide_init(position + 1, droite, t);
	}
}

void tri_rapide(int tableau[], int taille) {
	tri_rapide_init(0, taille - 1, tableau);
}
