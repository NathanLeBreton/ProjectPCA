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


typedef struct cellule{
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


void AnalyseChaine(s_cellule *c);
void EvaluerChaine(s_cellule *c);


