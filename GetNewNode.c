#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void *GetNewNode(unsigned int id, double *value){

	node *newNode = malloc(sizeof(node));
	if(newNode == NULL){
		perror("ERROR: impossibile allocare un nuovo nodo\n");
		exit(EXIT_FAILURE);
	}

	newNode->id = id;
	newNode->value = *value;
	newNode->nextNode = NULL;
	newNode->preNode = NULL;

	return newNode;
}
