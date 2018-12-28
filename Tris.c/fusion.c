#include "fusion.h"

void fusion(int gauche, int milieu, int droite, int t[])

/*
 *	Spécifications externes :
 *	  Fusionne les sous-tableau de t.
 *	- Entrée : Les indices de début, milieu et fin de t.
 *	- Sortie : Le sous-tableau t[gauche...droite] contient les
 *			   éléments de t[gauche...milieu] et de
 *			   t[milieu+1...droite] et est trié.
 */

{
	int i;
	int sg = gauche;
	int sd = milieu + 1;

	int *fus = (int *)malloc((milieu - gauche + 1) * sizeof(int));

	for (i = gauche; i <= milieu; i++) {
		fus[i - gauche] = t[i];
	}

	for (i = gauche; i <= droite; i++) {
		if (sg == milieu + 1)
			break;
		else if (sd == droite + 1 || fus[sg - gauche] < t[sd]) {
			t[i] = fus[sg - gauche];
			sg++;
		} else {
			t[i] = t[sd];
			sd++;
		}
	}

	free(fus);
}

void tri_fusion_init(int gauche, int droite, int t[])

/*
 *	Spécifications externes :
 *	  Tri le tableau avec la technique "diviser pour régner".
 *	- Entrée : Les indices de début et fin d'un sous-tableau de t, le tableau.
 *	- Sortie : Les éléments du sous-tableau t[gauche...droite] triés.
 */

{

	int milieu;

	if (gauche < droite) {
		milieu = (gauche + droite) / 2;
		tri_fusion_init(gauche, milieu, t);
		tri_fusion_init(milieu + 1, droite, t);
		fusion(gauche, milieu, droite, t);
	}
}

void tri_fusion(int tableau[], int taille) {
	tri_fusion_init(0, taille - 1, tableau);
}
