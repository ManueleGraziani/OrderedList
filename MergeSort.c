#include <stdio.h>
#include "Sort.h"

void MergeSort(list *list){

    node *listHeadptr = list->listHead, *listTailptr = list->listTail;
    node *ptrMiddle1 = NULL, *ptrMiddle2 = NULL;
	SortSubList(list, &listHeadptr, &listTailptr, list->listLen);

}
