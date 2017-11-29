#include "node.h"

int main(){

	int i=1;
	void *a=&i;
	int j=2;
	void *b=&j;
	int k=3;
	void *c=&k;
	int l=4;
	void *d =&l;

	void *test;


	node_t* node = creer_noeud();

	list_set_data(node,a);

	test = list_get_data(node);
	if(*(int *)test!=i)
		printf("valeur du noeud : %d\n", *(int *)test);


	node_t* node2 = list_insert(node, b);
	test = list_get_data(node2);
	if(*(int *)test!=j)
		printf("valeur du noeud : %d\n", *(int *)test);
	

	node_t* node3 = list_insert(node2,c);
	test = list_get_data(node3);
	if(*(int *)test!=k)
		printf("valeur du noeud : %d\n", *(int *)test);


	node_t* node4 = list_insert(node3,d);
	test = list_get_data(node4);
	if(*(int *)test!=l)
		printf("valeur du noeud : %d\n\n", *(int *)test);


	list_set_data(node2,c);
	test = list_get_data(node2);
	if(*(int *)test!=k)
		printf("valeur du noeud : %d\n", *(int *)test);

	list_set_data(node3,b);
	test = list_get_data(node3);
	if(*(int *)test!=j)
		printf("valeur du noeud : %d\n\n", *(int *)test);


	node_t* node5 = list_headRemove(node4);
	test = list_get_data(node5);
	if(*(int *)test!=j)
		printf("valeur du noeud : %d\n", *(int *)test);


	node_t* node6 = list_append(node3,a);
	test = list_get_data(node6);
	if(*(int *)test!=j)
		printf("valeur du noeud : %d\n", *(int *)test);


	node_t* node7 = list_remove(node3,c);
	test = list_get_data(node7);
	if(*(int *)test!=j)
		printf("valeur du noeud : %d\n", *(int *)test);


	node_t* node8 = list_remove(node3,b);
	test = list_get_data(node8);
	if(*(int *)test!=i)
		printf("valeur du noeud : %d\n", *(int *)test);


	list_destroy(node);
}












