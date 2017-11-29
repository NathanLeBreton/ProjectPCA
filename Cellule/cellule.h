#ifndef _CELL_H
#define _CELL_H

#include "../Liste/node.h"
#include "../Pile/pile.h"
#include <string.h>


typedef struct cellule s_cellule;

typedef struct token{
	enum {
	VALUE,REF,OPERATOR
	} type;

	union{
		double cst;
		s_cellule *ref;
		void (*operator)(pile_t* eval);
	} value;
}s_token;


struct cellule{
	char *chaine;
	double valeur;	
	node_t *lesTokens;
	node_t *lesCellules;
};


typedef struct feuilleCalcul{
	char *nomFichier;
	int nbLigne;
	int nbColonne;
	node_t *lesCellules;
}s_feuilleCalcul;

struct Operator {

};


void analyseChaine(s_cellule *c);
void evaluerChaine(s_cellule *c);

#endif //_CELL_H
