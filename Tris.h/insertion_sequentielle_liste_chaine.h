#ifndef INSERTION_SEQUENTIELLE_LIST_CHAINE__H
#define INSERTION_SEQUENTIELLE_LIST_CHAINE__H

#include "util.h"

// Création d'un alias à la structure
typedef struct Liste Liste;

// Création de la structure représentant une liste chaînée
struct Liste {
    int element;
    Liste* suivant;
};

Liste *inserer(Liste *liste, int valeur);
void liberer_liste(Liste **liste);
void tri_islc(int tableau[], int taille);

#endif /* INSERTION_SEQUENTIELLE_LIST_CHAINE__H */
