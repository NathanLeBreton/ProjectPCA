#ifndef _CELL_H
#define _CELL_H

#include "../Liste/node.h"
#include "../Pile/pile.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct cellule{
    char* nom;
    char *chaine;
    double valeur;
    node_t* lesTokens;
    node_t* refcellule;
    node_t* listeSuccesseurs;
    int nbSucc;
    int nbTok;
    int nbValue;
    int nbOper;
    int degrenegatif;
}s_cellule;

typedef struct operateur{
    char *nom;
    void (*operator)(pile_t* element);
}operateur_t;

typedef enum Type Type;
enum Type {VALUE,REF,OPERATOR};

typedef struct token{

    Type type;

    union {
        double cst;
        s_cellule* ref;
        void(*operator)(pile_t* eval);
    }value;
}s_token;

typedef struct feuille{
    char *nom;
    int ligne;
    int colonnes;
    node_t* listeCellules;
}feuille_t;


extern operateur_t operateur[4];
extern feuille_t feuille;
void initialisationOperateur();
void analyseCellule(s_cellule* cellule);
void evaluation(s_cellule* cellule);


void addition(pile_t* pile);
void multiplication(pile_t* pile);
void soustraction(pile_t* pile);
void division(pile_t* pile);


void graphedevaluation(s_cellule* cellule);

#endif //_CELL_H
