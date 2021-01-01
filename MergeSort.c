#include <stdio.h>
#include "Sort.h"

void MergeSort(list *list){
	
	SortSubList(list, list->listHead, list->listTail);

}
