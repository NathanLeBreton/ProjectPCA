#include "cellule.h"

void analyseChaine(s_cellule *cellule){
	char *chaine = strdup(cellule->chaine);
	char *tok = strtok(chaine," ");	

	if(chaine[0]=='='){

		cellule->lesTokens = list_create();

		printf("%s\n", tok);

	}

}
void evaluerChaine(s_cellule *c){


}
