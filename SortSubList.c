#include <stdio.h>
#include "Sort.h"

void SortSubList(list *list, node **listHead, node  **listTail){

	unsigned int middle1 = 0, middle2 = 0;
	node *ptrMiddle1 = NULL, *ptrMiddle2 = NULL;


	if( *listHead != *listTail ){

		middle1 = ((*listTail)->id + (*listHead)->id)/2;
		middle2 = middle1 + 1;

		ptrMiddle1 = *listHead;

		while(ptrMiddle1->id != middle1){
			ptrMiddle1 = ptrMiddle1->nextNode;
		}

		ptrMiddle2 = ptrMiddle1->nextNode;

		SortSubList(list,listHead,&ptrMiddle1);

        ptrMiddle1 = *listHead;

        while(ptrMiddle1->id != middle1){
            ptrMiddle1 = ptrMiddle1->nextNode;
        }

        ptrMiddle2 = ptrMiddle1->nextNode;


        SortSubList(list,&ptrMiddle2,listTail);

		Merge(list,listHead,&ptrMiddle1,&ptrMiddle2,listTail);
	}
}
