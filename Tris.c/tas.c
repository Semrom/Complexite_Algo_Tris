#include "tas.h"

void ajout_tas_rec(int t[], int i, int x) {
/*
 *	Spécifications externes :
 *	  Ajout récursivement les valeurs du tableau dans le tas.
 *	- Entrée : Le tableau, l'indice de la valeur, la valeur.
 */
	int parent = (i - 1) / 2;
	t[i] = x;
	if (i > 0 && x > t[parent]) {
		t[i] = t[parent];
		ajout_tas_rec(t, parent, x);
	}
}

void suppression_max_tas(int t[], int n) {
	/*
	 *	Spécifications externes :
	 *	  Suprime la vaeur maximum dans le tas.
	 *	- Entrée : Le tableau, la valeur.
	 */
	int i = 0, gauche = 1, droite = 2, max;

	permute(0, n - 1, t);

	while(gauche < n - 1) {
		if (droite < n - 1 && t[droite] > t[gauche]) {
			max = droite;
		} else {
			max = gauche;
		}

		if (t[i] < t[max]) {
			permute(i, max, t);
		} else {
			break;
		}

		i = max;
		gauche = 2 * i + 1;
		droite = 2 * i + 2;
	}
}

void construction_tas(int t[], int n) {
	/*
	 *	Spécifications externes :
	 *	  Construit le tas.
	 *	- Entrée : Le tableau, la taille du tableau.
	 */
	int i;
	for (i = 1; i < n; i++) {
		ajout_tas_rec(t, i, t[i]);
	}
}

void tri_par_tas(int tableau[], int taille) {
	construction_tas(tableau, taille);
	int i;
	
	for (i = taille; i > 1; i--) {
		suppression_max_tas(tableau, i);
	}
}
