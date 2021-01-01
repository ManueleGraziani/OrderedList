#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define BUFFER_LEN 100

void ReadFromFile(char *filePath,void *list){

	FILE *fptr = NULL;
	char buffer[BUFFER_LEN];
	double value;

	if( ( fptr = fopen(filePath,"r") ) == NULL){

		fprintf(stderr,"Error: impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}

	while(!feof(fptr)){

		fscanf(fptr,"%lf\n",&value);
		if(AppendNewNode(list, &value) == -1)
			exit(EXIT_FAILURE);
	}

	fclose(fptr);
	return;





}
