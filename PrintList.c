#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void PrintList(list *list){

	node *curNode = list->listHead;

	if(curNode == NULL){
		
		fprintf(stderr,"Errore: impossibile stampare la lista\n");
		exit(EXIT_FAILURE);

	}

	while(curNode != NULL){

		printf("%hd:%f -> ",curNode->id,curNode->value);
		curNode = curNode->nextNode;
	}
	
	puts("NULL");


		curNode = list->listTail;
	puts("stampa al contrario frocio che non sei bono a fa lo swap");
	while(curNode!=NULL){

		printf("%hd:%f ->",curNode->id,curNode->value);
		curNode = curNode->preNode;


	}

	puts("NULL");



	return;
}
