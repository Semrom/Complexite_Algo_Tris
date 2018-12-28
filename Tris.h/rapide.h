#ifndef RAPIDE__H
#define RAPIDE__H

#include "util.h"

void placer_pivot(int gauche, int droite, int t[], int *position);
void tri_rapide_init(int gauche, int droite, int t[]);
void tri_rapide(int tableau[], int taille);

#endif /*RAPIDE__H*/
