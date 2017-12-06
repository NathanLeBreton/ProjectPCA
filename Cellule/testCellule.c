//
// Created by le_brena on 29/11/17.
//
#include "cellule.h"

int main(){

    initialisationOperateur();

    s_cellule cellule;
    char* chainecarac= "= 5 5 +";
    cellule.nom = "C1";
    cellule.chaine = chainecarac;
    feuille.listeCellules = list_append(feuille.listeCellules,&cellule);

    analyse(&cellule);
    evaluation(&cellule);

    if(cellule.chaine!="= 5 5 +"){
        printf("%s\n",cellule.chaine);
    }
    if(cellule.valeur!=10){
        printf("%lf\n",cellule.valeur);
    }



    s_cellule cellule1;
    char* chainecarac1= "= C1 10 +";
    cellule1.nom = "C1";
    cellule1.chaine = chainecarac1;
    feuille.listeCellules = list_append(feuille.listeCellules,&cellule1);

    analyse(&cellule1);
    evaluation(&cellule1);

    if(cellule1.chaine!="= C1 10 +"){
        printf("%s\n",cellule1.chaine);
    }
    if(cellule1.valeur!=20){
        printf("%lf\n",cellule1.valeur);
    }


    s_cellule cellule2;
    char* chainecarac2= "= C1 C2 +";
    cellule2.nom = "C3";
    cellule2.chaine = chainecarac2;
    feuille.listeCellules = list_append(feuille.listeCellules,&cellule2);

    analyse(&cellule2);
    evaluation(&cellule2);

    if(cellule2.chaine!="= C1 C2 +"){
        printf("%s\n",cellule2.chaine);
    }
    if(cellule2.valeur!=40){
        printf("%lf\n",cellule2.valeur);
    }






    return 0;
}