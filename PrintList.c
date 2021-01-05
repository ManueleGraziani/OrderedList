#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void PrintList(list *list){

	node *curNode = list->listHead;
	unsigned int id = 1;

	// Viene verificato se la lista non è vuota
	if(curNode == NULL){
		fprintf(stderr,"Errore: impossibile stampare la lista\n");
		exit(EXIT_FAILURE);
	}

	while(curNode != NULL){
		printf("%d:%f -> ", id++, curNode->value);
		curNode = curNode->nextNode;
	}
	
	puts("NULL");
}
