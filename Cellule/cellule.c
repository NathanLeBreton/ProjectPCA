#include "cellule.h"

operateur_t operateur[4];
feuille_t feuille;

void initialisationOperateur(){

    operateur[0].nom = "+";
    operateur[0].operator = &addition;
    operateur[1].nom = "*";
    operateur[1].operator = &multiplication;
    operateur[2].nom = "-";
    operateur[2].operator = &soustraction;
    operateur[3].nom = "/";
    operateur[3].operator = &division;


    feuille.nom = "test";
    feuille.colonnes = 50;
    feuille.ligne = 50;

}

void analyseCellule(s_cellule* cellule){

    //initialisation des variables :
    double v = 0.0;
    cellule->lesTokens = list_create();
    cellule->valeur = 0.0;
    cellule->nbTok = 0;
    cellule->nbOper = 0;
    cellule->nbValue = 0;
    cellule->degrenegatif = 0;
    cellule->listeSuccesseurs = NULL;
    cellule->nbSucc = 0;


    node_t *listeCelluleExistant = feuille.listeCellules;
    s_cellule* c = NULL;
    s_cellule* tete = listeCelluleExistant->valeur;

    char char1;
    int int1;
    double double1;

    //dupliquer la chaine de la cellule
    char *chaine = strdup(cellule->chaine);

    //scinde la chaine avec pour delimiter les espaces
    char* tok = strtok(chaine," ");

    //si la chaine de la cellule commence par le signe "=" on l'analyse, sinon on ne fait rien
    if(strcmp(tok,"=") == 0){

        //on parcours la chaine de la cellule
        while (tok != NULL) {

            s_token *nouvToken = malloc(sizeof(s_token));
            if (nouvToken == NULL){
                return;
            }

            //v = strtod(tok, NULL);
            //si l'element de la chaine est une valeur
            if (sscanf(tok,"%lf",&double1)==1) {

                nouvToken->type = VALUE;
                nouvToken->value.cst = v;
                cellule->lesTokens = list_append(cellule->lesTokens, nouvToken); //on ajoute la valeur dans la liste des tokens de la cellule

                cellule->nbTok++;
                cellule->nbValue++;

            }

            //on parcours le tableau des operateur
            for (int j = 0; j < 4; ++j) {
                //on cherche l'operateur correspondant
                if (strcmp(tok, operateur[j].nom) == 0) {


                    nouvToken->type = OPERATOR;
                    nouvToken->value.operator = operateur[j].operator;
                    cellule->lesTokens = list_append(cellule->lesTokens, nouvToken);  //on ajoute l'operateur dans la liste des tokens de la cellule

                    cellule->nbTok++;
                    cellule->nbOper++;
                }
            }

            //si le token est sous le format "CHAR INT" -> c'est une reference vers une autre cellule
            if((sscanf(tok,"%c%d",&char1, &int1)==2) && (sscanf(tok,"%lf",&double1) != 1)){

                while (listeCelluleExistant->suivant != NULL) {

                    c = list_get_data(listeCelluleExistant);

                    //on verifie que le nom de la cellule existe dans la feuille
                    if (strcmp(tok, c->nom) == 0) {


                        nouvToken->type = REF;
                        nouvToken->value.ref = listeCelluleExistant->valeur;
                        cellule->lesTokens = list_append(cellule->lesTokens, nouvToken); //on ajoute la ref de cellule dans la liste des tokens de la cellule
                        tete->refcellule = list_insert(tete->refcellule, cellule);

                        cellule->nbTok++;
                        cellule->nbValue++;

                        c->listeSuccesseurs = list_insert(c->listeSuccesseurs, cellule->nom);
                        c->nbSucc++;

                        cellule->degrenegatif++;
                    }

                    listeCelluleExistant = listeCelluleExistant->suivant;
                }
            }
            //on avance dans le parcours de la chaine pour analyser les caractere suivant
            listeCelluleExistant = feuille.listeCellules;
            tok = strtok(NULL, " ");
        }
    }

    return;
}

void evaluation(s_cellule* cellule){

    //l'evaluation est possible seulement si la liste de token de la cellule n'est pas vide ( apres l'analyse )
    if(cellule->lesTokens == NULL){
        return;
    }

    //si la formule de la cellule est correcte
    if(cellule->nbValue==cellule->nbOper+1) {

        s_token *token = NULL;
        s_cellule *celluleref;
        node_t *listetoken = cellule->lesTokens;
        pile_t *pile = pile_creer(cellule->nbTok);


        int i = 0;
        while (i < cellule->nbTok) {

            token = list_get_data(listetoken);

            if (token->type == VALUE) {
                pile_empiler(pile, token->value.cst);
            }
            if (token->type == REF) {
                celluleref = token->value.ref;
                pile_empiler(pile, celluleref->valeur);
            }
            if (token->type == OPERATOR) {
                token->value.operator(pile);
            }

            listetoken = listetoken->suivant;
            i++;
        }

        pile_depiler(pile, &cellule->valeur);
    }
    return;
}

//les fonctions de calcul :

//ajoute la valeur de l'addiction dans la pile
void addition(pile_t* pile){
    double a , b, r;
    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    r = a+b;
    pile_empiler(pile,r);

    return;
}

void multiplication(pile_t* pile){

    double a , b, r;
    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    r = a*b;

    pile_empiler(pile,r);
    return;
}

void soustraction(pile_t* pile){

    double a, b, r;
    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    r = a-b;

    pile_empiler(pile,r);
    return;
}

void division(pile_t* pile){

    double a , b, r;
    pile_depiler(pile,&a);
    pile_depiler(pile,&b);

    r = b/a;

    pile_empiler(pile,r);
    return;
}




void modifCellule(s_cellule* cellule) {



}