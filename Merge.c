#include <stdio.h>
#include <string.h>
#include "Sort.h"


void Merge(list *list, node **listHead, node **middle1, node **middle2, node **listTail){

	node *leftIdx = *listHead, *rightIdx = *middle2;
	node *tempNodePtr = NULL;
	unsigned int tempId;

	while( (leftIdx != (*middle1)->nextNode) && (rightIdx != (*listTail)->nextNode) ){

		if(leftIdx->value <= rightIdx->value){
			leftIdx = leftIdx->nextNode;
		}else{

            tempId = leftIdx->id;
            leftIdx->id = rightIdx->id;
            rightIdx->id = tempId;

            if(leftIdx != *middle1 && rightIdx != *listTail) {
                tempId = (*listTail)->id;
                (*listTail)->id = (*middle1)->id;
                (*middle1)->id = tempId;
            }


		    // Casp in cui è la coda della lista
		    if( (*listTail)->nextNode == NULL){
		        list->listTail = *middle1;
		        (*middle1)->nextNode = NULL;

		    }else{
                (*middle1)->nextNode = (*listTail)->nextNode;

                tempNodePtr = (*middle1)->nextNode;
                tempNodePtr->preNode = *middle1;
		    }


		    // Caso in cui è la testa della lista
		    if( leftIdx->preNode == NULL){
		        list->listHead = rightIdx;
                rightIdx->preNode = NULL;

		    }else{

                rightIdx->preNode = leftIdx->preNode;

                tempNodePtr = rightIdx->preNode;
                tempNodePtr->nextNode = rightIdx;
		    }



            (*listTail)->nextNode = leftIdx;
		    leftIdx->preNode = *listTail;

            tempNodePtr = *listTail;

		    *listTail = *middle1;
		    *middle1 = tempNodePtr;

		    *middle2 = leftIdx;




            if(leftIdx == *listHead)
                *listHead = rightIdx;

            tempNodePtr = leftIdx;
            leftIdx = rightIdx;
            rightIdx = tempNodePtr;

            if(leftIdx->nextNode != NULL)
                leftIdx = leftIdx->nextNode;
            else
                break;


		}

	}


	node *curNode = list->listHead;
	unsigned int i = 1;
	while(curNode != NULL){
		curNode->id = i++;
		curNode = curNode->nextNode;


	}


}
