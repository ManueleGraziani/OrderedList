#include <stdio.h>
#include <stdlib.h>
#include "File.h"
#include "Sort.h"

int main(int argc, char *argv[]){

	list list;
	double value = 0;

	list.listHead = NULL;
	list.listTail = NULL;
	list.listLen = 0;
	
	if(argv[1] == NULL || argv[2] == NULL){
		fprintf(stderr,"Error: sintassi errata\n"
				"Digitare %s [FILE PATH] [NUMBER]\n",*argv);
		exit(EXIT_FAILURE);
	}

	ReadFromFile(argv[1],&list);
	PrintList(&list);

	printf("\n\nlunghezza lista %hd\n",list.listLen);

	puts("Lista Ordinata");
	MergeSort(&list);

	
	PrintList(&list);


}
