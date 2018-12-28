#include <time.h>

#include "bulles.h"
#include "fusion.h"
#include "insertion_dichotomique.h"
#include "insertion_sequentielle.h"
#include "insertion_sequentielle_liste_chaine.h"
#include "rapide.h"
#include "selection_permutation.h"
#include "tas.h"
#include "arbre_binaire.h"

// Pointeurs de fonctions
void (*listeFonctions[9])(int[], int) = {tri_insertion_seq, tri_fusion, tri_insertion_dichotomique, tri_rapide, tri_islc, tri_selection_permutation, tri_arbre_binaire, tri_a_bulles, tri_par_tas};

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("usage : ./main <indice_tri>");
		fflush(stdout);
		exit(1);
	}

	void (*fonctions)(int[], int);

	printf("Taille de tableau (x20), temps (ms)\n");
	fflush(stdout);

	// Démarre le tri correspondant au numéro contenu dans argv[1]
	switch (*argv[1]) {
		case '1':
			fonctions = listeFonctions[0];
			break;
		case '2':
			fonctions = listeFonctions[1];
			break;
		case '3':
			fonctions = listeFonctions[2];
			break;
		case '4':
			fonctions = listeFonctions[3];
			break;
		case '5':
			fonctions = listeFonctions[4];
			break;
		case '6':
			fonctions = listeFonctions[5];
			break;
		case '7':
			fonctions = listeFonctions[6];
			break;
		case '8':
			fonctions = listeFonctions[7];
			break;
		case '9':
			fonctions = listeFonctions[8];
			break;
		default:
			printf("Erreur\n");
			fflush(stdout);
			break;
	}

	int i;
	int j;
	int k;
	int t;
	int arret = 0;
	int indice_tmp;
	double m = 0;
	double temps[20];
	double time_add = 0;
	TABLEAU tab;

	// Stockage des 15 tailles de tableaux
	int tab_taille[15] = {100, 500, 5000, 10000, 50000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};

	srand(time(0));
	// Parcours des tailles
	for	(t = 0; t < 15; t++) {
		// Parcours 20 fois pour chaque tailles
		for (i = 0; i < 20; i++) {
			// Remplissage du tableau aléatoirement
			for(j = 0; j < tab_taille[t]; j++) {
				tab[j] = ((int) rand() % tab_taille[t]);
			}

			clock_t debut, fin;
			debut = clock();
			(*fonctions)(tab, tab_taille[t]);
			fin = clock();
			double time = (((double)(fin - debut)) / CLOCKS_PER_SEC) * 1000.0;

			time_add += time;

			// Si ça dépasse 5 minutes
			if (time_add >= 300000) {
				printf("%d, Temps > 5 min.\n", tab_taille[t]);
				fflush(stdout);
				indice_tmp = i;
				arret = 1;
				break;
			}

			// Sotckage du temps pour calcul de la moyenne sur les 20 tableaux
			temps[i] = time;
		}

		if (arret == 1) {
			exit(1);
		}
		else {
			for (k = 0; k < 20; k++) {
				m += temps[k];
			}

			// Affichage dans fichier csv 
			printf("%d, %f\n", tab_taille[t], m / 20);
			fflush(stdout);
		}
	}

	return 0;
}
