#ifndef ARBRE_BINAIRE__H
#define ARBRE_BINAIRE__H

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

typedef struct Noeud {
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droit;
} *noeud_t;

typedef noeud_t arbre_t;

arbre_t creer_arbre(int valeur, arbre_t gauche, arbre_t droit);
void detruire_arbre(arbre_t arbre);
arbre_t insere(arbre_t arbre, int valeur);
int tri_recursif(arbre_t arbre, int i, int tableau[]);
void tri_arbre_binaire(int tableau[], int taille);

#endif /* ARBRE_BINAIRE__H */
