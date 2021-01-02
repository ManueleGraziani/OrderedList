#include <stdio.h>
#include <string.h>
#include "Sort.h"


void Merge(list *list, node **listHead, node **middle1, node **middle2, node **listTail){

	node *leftIdx = *listHead, *rightIdx = *middle2;
	node *preNode = NULL, *nextNode = NULL, tempNode;

	while( (leftIdx->id <= (*middle1)->id) && (rightIdx->id <= (*listTail)->id) ){

		if(leftIdx->value <= rightIdx->value){
			leftIdx = leftIdx->nextNode;
		}else{

		    *listHead = *middle2;
		    *listTail =


            if((*listTail)->nextNode == NULL){
                list->listTail


            }else{


            }


            if((*listHead)->preNode == NULL){


            }else{

            }





		}

	}

	node *curNode = list->listHead;
	unsigned int i = 1;
	while(curNode != NULL){
		curNode->id = i++;
		curNode = curNode->nextNode;


	}


}
