#include <stdio.h>
#include "List.h"

int AppendNewNode(list *list, double *value){

	node *newNode = GetNewNode(value);
	list->listLen++;

	if(list->listHead == NULL){
		
		list->listHead = newNode;
		list->listTail = newNode;
		newNode->preNode = NULL;
		return 0;

	}else{

		newNode->preNode = list->listTail;
		list->listTail->nextNode = newNode;
		list->listTail = newNode;
		return 0;
	}

}