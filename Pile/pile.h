#ifndef _PILE_H
#define _PILE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct pile pile_t;
struct pile{
	double *donnees;
	int tailleMax, taille, iterateur;
};

pile_t *pile_creer(int nb_places);
void pile_detruire(pile_t *p);
void pile_initialiser(pile_t *p);
int pile_place_occupees(const pile_t *p);
int pile_place_libre(const pile_t *p);

int pile_depiler(pile_t *p, double *el);

int pile_empiler(pile_t *p, double el);

void pile_initialiser_iterateur(pile_t *p);

int pile_obtenir_element_suivant(pile_t *p, double *el);



#endif









