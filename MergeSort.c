#include <stdio.h>
#include "Sort.h"

void MergeSort(list *list){

    node *listHeadptr = list->listHead;
    node *listTailptr = list->listTail;

    puts("\n -Inizio della procedura di ordinamento- \n");
	SortSubList(list, &listHeadptr, &listTailptr, list->listLen);

}
