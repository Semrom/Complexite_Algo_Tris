#include "arbre_binaire.h"

arbre_t creer_arbre(int valeur, arbre_t gauche, arbre_t droit) {
/*
 *	Spécifications externes :
 *  - Entrée : la première valeur de l’arbre, les sous arbres G et D
 *	- Sortie : l’arbre crée
 */

    arbre_t arbre = malloc(sizeof(struct Noeud));
    arbre->valeur = valeur;
    arbre->gauche = gauche;
    arbre->droit = droit;

    return arbre;
}

void detruire_arbre(arbre_t arbre) {
/*
 *	Spécifications externes :
 *    - Entrée : un arbre à détruire
 *	Libère la mémoire allouée à l’arbre.
 */
    if (arbre == NULL)
        return;
    detruire_arbre(arbre->gauche);
    detruire_arbre(arbre->droit);
    free(arbre);
}

arbre_t insere(arbre_t arbre, int valeur) {
/*
 *	Spécifications externes :
 *    - Entrée : un arbre, la valeur à insérer dans cet arbre
 *	  - Sortie : l’arbre contenant la valeur
 */

    if (arbre == NULL)
        return creer_arbre(valeur, NULL, NULL);
    else {
        if (valeur < arbre->valeur)
            arbre->gauche = insere(arbre->gauche, valeur);
        else
            arbre->droit = insere(arbre->droit, valeur);

            return arbre;
    }
}

int tri_recursif(arbre_t arbre, int i, int tableau[]) {
/*
 *	Spécifications externes :
 *    - Entrée : un arbre, un indice de départ, un tableau
 *	  - Sortie : la position indiquant l’emplacement de l’élément dans l’arbre
 * 	Tri récursivement l’arbre et insert les valeurs triés dans le tableau.
 */
    int j = 0;
    if (arbre == NULL) {
        return j;
    }

    // Tri récursif pour l’arbre gauche (important pour la complexité)
    j = tri_recursif(arbre->gauche, i, tableau);
    tableau[i + j] = arbre->valeur;
    j++;
    // Tri récursif pour l’arbre droit (important pour la complexité)
    j += tri_recursif(arbre->droit, i + j, tableau);
    return j;
}

void tri_arbre_binaire(int tableau[], int taille) {
/*
 *	Spécifications externes :
 *    - Entrée : un tableau de taille « taille »
 *	Insertion des valeurs du tableau dans un arbre.
 */

    int i;
    arbre_t arbre = NULL;

    for (i = 0; i < taille; i++) {
        arbre = insere(arbre, tableau[i]);
    }

    tri_recursif(arbre, 0, tableau);
    detruire_arbre(arbre);
}
