#include "pile.h"

int main(){


	pile_t *p;
	double a;
	int res;
	
	p=pile_creer(5);
	pile_initialiser(p);

	res = pile_place_libre(p);
	if(res!=5)(printf("place libre incorrect"));

	res=pile_place_occupees(p);
	if(res!=0)
		printf("place occupee incorrect");


	res=pile_empiler(p,2);
	if(res!=0)
		printf("echec empilement");

	res=pile_place_libre(p);
	if(res!=4)(printf("place libre incorrect"));

	res=pile_place_occupees(p);
	if(res!=1)
		printf("place occupee incorrect");

	pile_empiler(p,2);
	pile_empiler(p,3);
	pile_empiler(p,4);
	pile_empiler(p,5);
	
	res=pile_place_libre(p);
	if(res!=0)(printf("place libre incorrect"));

	res=pile_place_occupees(p);
	if(res!=5)
		printf("place occupee incorrect");

	res=pile_empiler(p,6);
	if(res!=-1)(printf("erreur emplilement"));

	res = pile_depiler(p,&a);
	if(res!=0)(printf("erreur depilement"));

	res = a;
	if(res!=5)(printf("erreur element deplilé"));

	res = pile_depiler(p,&a);
	if(res!=0)(printf("erreur depilement(2)"));

	res = a;
	if(res!=4)(printf("erreur element deplilé(2)"));
	
	res=pile_place_libre(p);
	if(res!=2)(printf("place libre incorrect"));

	res=pile_place_occupees(p);
	if(res!=3)
		printf("place occupee incorrect");
	return 0;

}



























