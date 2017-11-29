#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node node_t;
struct node{
	void *valeur;
	node_t *suivant;
};


node_t *list_create(void);
node_t *creer_noeud(void);
void * list_get_data(const node_t *node);
void list_set_data(node_t *node, void *data);
node_t *list_insert(node_t *head, void *data);
node_t *list_append(node_t *head, void *data);
node_t *list_remove(node_t *head, void *data);
node_t *list_headRemove(node_t *head);
node_t *list_destroy(node_t *head);


#endif
