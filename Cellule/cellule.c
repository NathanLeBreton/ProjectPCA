#include "cellule.h"

void AnalyseChaine(s_cellule *cellule){
	char *chaine = strdup(cellule->chaine);
	char *tok = strtok(chaine," ");	

	if(chaine[0]=='='){

		cellule->lesTokens = list_create();

		printf("%s\n", tok);

	}

}
void EvaluerChaine(s_cellule *c){


}
