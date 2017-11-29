#include "node.h"


node_t* list_creat(void){
	return NULL;
}

node_t *creer_noeud(void){

	node_t* n;
	if((n=(node_t*)malloc(sizeof(node_t)))==NULL){
		return NULL;
	}
	n->valeur=NULL;
	n->suivant=NULL;

	return n; 
}

inline void *list_get_data(const node_t *node){

	if(node!=NULL)
		return node->valeur;
	else{
		return 0;
	}
}

inline void list_set_data(node_t *node, void *data){

	if(node!=NULL)
		node->valeur=data;
}

node_t *list_insert(node_t *head, void *data){

	node_t *node=creer_noeud();
	list_set_data(node,data);
	if(head!=NULL)
	{
		node->suivant=head;
	}
	return node;		
}

node_t *list_append(node_t *head, void *data){

	if(head!=NULL){
		node_t *node=head;
		while(node!=NULL && node->suivant!=NULL){
			node=node->suivant;
		}
		node->suivant=creer_noeud();

		list_set_data(node->suivant,data);
		return head;
	}
	else{
		node_t *node=creer_noeud();
		list_set_data(node,data);
		return node;
	}
}


node_t *list_remove(node_t *head, void *data){
	

	if(head!=NULL)
	{
		node_t* node=head;
		node_t* precedent=NULL;
		int *donnee=(int*)node->valeur;

		while(node!=NULL && *donnee!=*(int*)data)
		{
			precedent=node;	
			node=node->suivant;
			donnee=(int*)node->valeur;
		}
		if(precedent==NULL)
		{
			head=node->suivant;
			free(node);
			return head;
		}
		else{
			precedent->suivant=node->suivant;
			free(node);
			return head;
		}	
	}
	else
		return NULL;
}

node_t *list_headRemove(node_t *head){

	if(head!=NULL){
		node_t* node=head;
		if(head->suivant!=NULL){
			head=node->suivant;
			free(node);
			return head;
		}
		return NULL;	
	}
	else{
		return NULL;
	}
}

node_t *list_destroy(node_t *head){

	if(head!=NULL){
		node_t* n=head;
		
		while(head!=NULL){
			head=n->suivant;
			free(n);
			n=head;
		}
	}
	return NULL;
}
