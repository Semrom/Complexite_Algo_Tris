#include "insertion_sequentielle_liste_chaine.h"

Liste *inserer(Liste *liste, int valeur)

/*
 *	Spécifications externes :
 *	  Insert un élément dans la liste.
 *	- Entrée : la liste à utiliser, la valeur à insérer.
 *	- Sortie : la liste trié.
 */

{
	Liste *nouveau = malloc(sizeof *nouveau);

	if (nouveau == NULL)
	{
		exit(EXIT_FAILURE);
	} else {
		Liste *tmp = NULL;
		Liste *liste2 = liste;
		nouveau->element = valeur;
		// A la dernière insertion dans la liste on aura parcouru cette
		// boucle n fois
		while (liste2 != NULL && liste2->element <= valeur)
		{
			tmp = liste2;
			liste2 = liste2->suivant;
		}

		nouveau->suivant = liste2;

		if (tmp != NULL) {
			tmp->suivant = nouveau;
		} else {
			liste = nouveau;
		}

	}

	return liste;
}

void afficher_liste(Liste *liste)

/*
 *	Spécifications externes :
 *	  Affiche la liste complète.
 */

{
	while (liste != NULL)
	{
		printf("%d\n", liste->element);
		liste = liste->suivant;
	}

	printf("\n");
}

void liberer_liste(Liste **liste)

/*
 *	Spécifications externes :
 *    Libère la mémoire allouée à la liste.
 */

{
	while (*liste != NULL)
	{
		Liste *tmp = (*liste)->suivant;
		free(*liste), *liste = NULL;
		*liste = tmp;
	}
}

void tri_islc(int tableau[], int taille) {
	Liste *liste = NULL;
	// Parcours n fois (“taille” fois)
	for (int i = 0; i < taille; i++) {
		liste = inserer(liste, tableau[i]);
	}

	//afficher_liste(liste);
	liberer_liste(&liste);
}
