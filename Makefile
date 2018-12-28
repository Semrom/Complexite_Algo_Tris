SHELL  = /bin/bash
CC     = gcc
CFLAGS = -Wall -W -std=c99
LIBS   =
EXECS = main

.c.o :
	$(CC) -c $(CFLAGS) $*.c

help ::
	@echo "Options du make : help all clean distclean"

all :: $(EXECS)

$(EXECS): main.o util.o insertion_sequentielle.o insertion_dichotomique.o bulles.o fusion.o rapide.o tas.o insertion_sequentielle_liste_chaine.o selection_permutation.o arbre_binaire.o
	$(CC) -o $(EXECS) main.o util.o insertion_sequentielle.o insertion_dichotomique.o bulles.o fusion.o rapide.o tas.o insertion_sequentielle_liste_chaine.o selection_permutation.o arbre_binaire.o

main.o: main.c insertion_sequentielle.h insertion_dichotomique.h bulles.h fusion.h rapide.h tas.h insertion_sequentielle_liste_chaine.h selection_permutation.h arbre_binaire.h
	$(CC) -o main.o -c main.c $(CFLAGS)

util.o: util.c util.h
	$(CC) -o util.o -c util.c $(CFLAGS)

insertion_sequentielle.o: insertion_sequentielle.c insertion_sequentielle.h
	$(CC) -o insertion_sequentielle.o -c insertion_sequentielle.c $(CFLAGS)

insertion_dichotomique.o: insertion_dichotomique.c insertion_dichotomique.h
	$(CC) -o insertion_dichotomique.o -c insertion_dichotomique.c $(CFLAGS)

bulles.o: bulles.c bulles.h
	$(CC) -o bulles.o -c bulles.c $(CFLAGS)

fusion.o: fusion.c fusion.h
	$(CC) -o fusion.o -c fusion.c $(CFLAGS)

rapide.o: rapide.c rapide.h
	$(CC) -o rapide.o -c rapide.c $(CFLAGS)

tas.o: tas.c tas.h
	$(CC) -o tas.o -c tas.c $(CFLAGS)

insertion_sequentielle_liste_chaine.o: insertion_sequentielle_liste_chaine.c insertion_sequentielle_liste_chaine.h
	$(CC) -o insertion_sequentielle_liste_chaine.o -c insertion_sequentielle_liste_chaine.c $(CFLAGS)

selection_permutation.o: selection_permutation.c selection_permutation.h
	$(CC) -o selection_permutation.o -c selection_permutation.c $(CFLAGS)

arbre_binaire.o: arbre_binaire.c arbre_binaire.h
	$(CC) -o arbre_binaire.o -c arbre_binaire.c $(CFLAGS)

clean ::
	\rm -f *.o core

distclean :: clean
	\rm -f *% $(EXECS)
