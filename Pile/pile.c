#include "pile.h"

pile_t *pile_creer(int nb_places){

	if(nb_places<=0) return NULL;

	pile_t *p = malloc(sizeof(pile_t));

	p->donnees = (double*)malloc(nb_places*sizeof(double));
	p->tailleMax = nb_places;
	pile_initialiser(p);
	

	return p;		
}

void pile_detruire(pile_t *p){
	
	if(p!=NULL)
	{
		free(p->donnees);
		free(p);
	}	
}

void pile_initialiser(pile_t *p){

	p->taille=0;
	p->iterateur=0;

}

int pile_place_occupees(const pile_t *p){

	if(p==NULL)
	{
		return -1;
	}
	return p->taille;
}


int pile_place_libre(const pile_t *p){
	
	if(p==NULL)
	{
		return -1;
	}
	return (p->tailleMax)-(p->taille);
}


inline int pile_depiler(pile_t *p, double *el){


	if(0<pile_place_occupees(p))
	{ 
		*el=p->donnees[p->taille-1];
		p->taille--;		
	
		return 0;
	}
	else
	{
		*el=0;
		return -1;
	}
}


inline int pile_empiler(pile_t *p, double el){

	if(0<pile_place_libre(p))
	{ 
		p->donnees[p->taille]=el;
		p->taille++;
		return 0;
	}
	else
	{
		return -1;
	}
}


void pile_initialiser_iterateur(pile_t *p){

	p->iterateur=0;
}

int pile_obtenir_element_suivant(pile_t *p, double *el){

	if(0<pile_place_occupees(p))
	{ 
		if(0<=p->iterateur && p->iterateur<pile_place_occupees(p))
		{
			*el=p->donnees[p->iterateur];
			p->iterateur++;
			return 0;
		}
		else
		{
			*el=0;	
			return -1;
		}
	}
	else
	{
		*el=0;
		return -1;	
	}			
}




