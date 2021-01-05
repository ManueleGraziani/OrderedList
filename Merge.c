#include <string.h>
#include "Sort.h"

static void __SwapList(list *list, node **listHead, node **middle1, node **listTail, node *leftIdx, node *rightIdx);

void Merge(list *list, node **listHead, node **middle1, node **middle2, node **listTail){

	node *leftIdx = *listHead, *rightIdx = *middle2;
	node *tempNodePtr = NULL;

	while( (leftIdx != (*middle1)->nextNode) && (rightIdx != (*listTail)->nextNode) ){

		if(leftIdx->value <= rightIdx->value){
			leftIdx = leftIdx->nextNode;
		}else{

		    /*
		     * Lo scopo di questo algoritmo è di invertire le due liste partendo dai loro rispettivi indici,
		     * questo viene fatto per poter mantenere l'ordinamento dei valori contenuti nelle liste.
		    */
		    __SwapList(list,listHead,middle1,listTail,leftIdx,rightIdx);

		    // In questa fase si invertono i puntatori
            tempNodePtr = *listTail;

		    *listTail = *middle1;
		    *middle1 = tempNodePtr;
		    *middle2 = leftIdx;

            tempNodePtr = leftIdx;
            leftIdx = rightIdx;
            rightIdx = tempNodePtr;

            if(leftIdx->nextNode != NULL)
                leftIdx = leftIdx->nextNode;
            else
                break;


		}

	}



}

static void __SwapList(list *list, node **listHead, node **middle1, node **listTail, node *leftIdx, node *rightIdx){

    node *tempNodePtr = NULL;

    // Caso in cui è la coda della lista
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

    if(leftIdx == *listHead) {
        *listHead = rightIdx;
    }

    (*listTail)->nextNode = leftIdx;
    leftIdx->preNode = *listTail;

}