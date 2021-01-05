#include <stdio.h>
#include "Sort.h"

void SortSubList(list *list, node **listHead, node  **listTail, unsigned int listLen){

	unsigned int middle1, position;
	node *ptrMiddle1 = NULL, *ptrMiddle2 = NULL;

	if( *listHead != *listTail ){

		middle1 = (listLen +1)/2;
		ptrMiddle1 = *listHead;

		for(position = 1;position < middle1;position++){
			ptrMiddle1 = ptrMiddle1->nextNode;
		}

		ptrMiddle2 = ptrMiddle1->nextNode;

		SortSubList(list,listHead,&ptrMiddle1,middle1);
        SortSubList(list,&ptrMiddle2,listTail,(listLen-middle1));
		Merge(list,listHead,&ptrMiddle1,&ptrMiddle2,listTail);
	}
}
