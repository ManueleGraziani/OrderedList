#include <stdlib.h>
#include "List.h"

void DeallocationList(list* list){

    node *curNode = list->listHead, *nodeToFree = NULL;

    while(curNode != NULL)
    {
        nodeToFree = curNode;
        curNode = curNode->nextNode;

        free(nodeToFree);
    }
}