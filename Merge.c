#include <stdio.h>
#include <string.h>
#include "Sort.h"


void Merge(list *list, node **listHead, node **middle1, node **middle2, node **listTail){

	node *leftIdx = *listHead, *rightIdx = *middle2;
	node *swapNode = NULL, *tempNode = NULL; 

	while( (leftIdx->id <= (*middle1)->id) && (rightIdx->id <= (*listTail)->id) ){

		if(leftIdx->value <= rightIdx->value){
			leftIdx = leftIdx->nextNode;	
		}else{
			swapNode = rightIdx;
			rightIdx = rightIdx->nextNode;

			if(rightIdx == NULL){
                (*middle1)->nextNode = NULL;
				list->listTail = *middle1;
				*listTail = *middle1;
			}
			
			else{
				rightIdx->preNode = *middle1;
                (*middle1)->nextNode = rightIdx;
			}
			
			swapNode->nextNode = leftIdx;
			swapNode->preNode = leftIdx->preNode;
			if(leftIdx->preNode == NULL)
				list->listHead = swapNode;
			else{
				tempNode = swapNode->preNode;
				tempNode->nextNode = swapNode;
			}

			if(leftIdx == *listHead)
			    *listHead = swapNode;


		}
		if(rightIdx==NULL)
		    break;
		if(rightIdx->id > (*listTail)->id)
		    *listTail = *middle1;

	}

	node *curNode = list->listHead;
	unsigned int i = 1;
	while(curNode != NULL){
		curNode->id = i++;
		curNode = curNode->nextNode;


	}


}
