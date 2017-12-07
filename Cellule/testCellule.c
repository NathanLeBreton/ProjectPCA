//
// Created by le_brena on 29/11/17.
//
#include "cellule.h"

int main(){

    initialisationOperateur();

    //test addition valeur + valeur
    s_cellule c;
    char* chainecarac= "= 5 5 +";
    c.nom = "C1";
    c.chaine = chainecarac;
    feuille.listeCellules = list_append(feuille.listeCellules,&c);
    analyseCellule(&c);
    evaluation(&c);

    if(c.chaine!="= 5 5 +"){
        printf("%s\n",c.chaine);
    }
    if(c.valeur!=10){
        printf("%lf\n",c.valeur);
    }




    //test addition valeur + refcellule
    s_cellule c1;
    char* chainecarac1= "= C1 10 +";
    c1.nom = "C1";
    c1.chaine = chainecarac1;
    feuille.listeCellules = list_append(feuille.listeCellules,&c1);
    analyseCellule(&c1);
    evaluation(&c1);

    if(c1.chaine!="= C1 10 +"){
        printf("%s\n",c1.chaine);
    }
    if(c1.valeur!=20){
        printf("%lf\n",c1.valeur);
    }



    //test addition refcellule+refecellule
    s_cellule c2;
    char* chainecarac2= "= C1 C2 +";
    c2.nom = "C3";
    c2.chaine = chainecarac2;
    feuille.listeCellules = list_append(feuille.listeCellules,&c2);
    analyseCellule(&c2);
    evaluation(&c2);

    if(c2.chaine!="= C1 C2 +"){
        printf("%s\n",c2.chaine);
    }
    if(c2.valeur!=40){
        printf("%lf\n",c2.valeur);
    }



    //test addition avec des refcellules inexistantes
    s_cellule c3;
    char* chainecarac3= "= C4 C5 +";
    c3.nom = "C3";
    c3.chaine = chainecarac3;
    feuille.listeCellules = list_append(feuille.listeCellules,&c3);
    analyseCellule(&c3);
    evaluation(&c3);

    if(c3.chaine!="= C4 C5 +"){
        printf("%s\n",c3.chaine);
    }
    if(c3.valeur!=0){
        printf("%lf\n",c3.valeur);
    }




    //test d'erreur : si il manque le "="
    s_cellule c4;
    char* chaincarac4 = "10 10 +";
    c4.nom="C4";
    c4.chaine=chaincarac4;

    feuille.listeCellules = list_append(feuille.listeCellules,&c4);
    analyseCellule(&c4);
    evaluation(&c4);

    if(c4.chaine!="10 10 +"){
        printf("%s\n",c4.chaine);
    }
    if(c4.valeur!=0){
        printf("%lf\n",c4.valeur);
    }




    //test soustraction
    s_cellule c5;
    char* chaincarac5 = "= 5 10 -";
    c5.nom="C5";
    c5.chaine=chaincarac5;

    feuille.listeCellules = list_append(feuille.listeCellules,&c5);
    analyseCellule(&c5);
    evaluation(&c5);

    if(c5.chaine!="= 5 10 -"){
        printf("%s\n",c5.chaine);
    }
    if(c5.valeur!=5){
        printf("%lf\n",c5.valeur);
    }




    //test multiplication
    s_cellule c6;
    char* chaincarac6 = "= 5 10 *";
    c6.nom="C6";
    c6.chaine=chaincarac6;

    feuille.listeCellules = list_append(feuille.listeCellules,&c6);
    analyseCellule(&c6);
    evaluation(&c6);

    if(c6.chaine!="= 5 10 *"){
        printf("%s\n",c6.chaine);
    }
    if(c6.valeur!=50){
        printf("%lf\n",c6.valeur);
    }



    //test division
    s_cellule c7;
    char* chaincarac7 = "= 10 5 /";
    c7.nom="C7";
    c7.chaine=chaincarac7;

    feuille.listeCellules = list_append(feuille.listeCellules,&c7);
    analyseCellule(&c7);
    evaluation(&c7);

    if(c7.chaine!="= 10 5 /"){
        printf("%s\n",c7.chaine);
    }
    if(c7.valeur!=2){
        printf("%lf\n",c7.valeur);
    }





    //test plus de 2 valeur :
    s_cellule c8;
    char* chaincarac8 = "= 10 5 4 + +";
    c8.nom="C8";
    c8.chaine=chaincarac8;

    feuille.listeCellules = list_append(feuille.listeCellules,&c8);
    analyseCellule(&c8);
    evaluation(&c8);

    if(c8.chaine!="= 10 5 4 + +"){
        printf("%s\n",c8.chaine);
    }
    if(c8.valeur!=19){
        printf("%lf\n",c8.valeur);
    }



    //test d'erreur : il y a trop de valeur :
    s_cellule c9;
    char* chaincarac9 = "= 10 5 4 + ";
    c9.nom="C9";
    c9.chaine=chaincarac9;

    feuille.listeCellules = list_append(feuille.listeCellules,&c9);
    analyseCellule(&c9);
    evaluation(&c9);

    if(c9.chaine!="= 10 5 4 + "){
        printf("%s\n",c9.chaine);
    }
    if(c9.valeur!=0){
        printf("%lf\n",c9.valeur);
    }



    //test d'erreur : si il n'y a pas assez de valeur dans la cellule :
    s_cellule c10;
    char* chaincarac10 = "= 10 +";
    c10.nom="C10";
    c10.chaine=chaincarac10;

    feuille.listeCellules = list_append(feuille.listeCellules,&c10);
    analyseCellule(&c10);
    evaluation(&c10);

    if(c10.chaine!="= 10 +"){
        printf("%s\n",c10.chaine);
    }
    if(c10.valeur!=0){
        printf("%lf\n",c10.valeur);
    }

    return 0;
}