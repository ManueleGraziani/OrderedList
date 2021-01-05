#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define BUFFER_LEN 10

void ReadFromFile(char *filePath,void *list){

	FILE *fptr = NULL; // Puntatore al file
	char buffer[BUFFER_LEN], **endPtr = NULL;
	double value;

	// Apertura del file
	if( ( fptr = fopen(filePath,"r") ) == NULL){
		fprintf(stderr,"Error: impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}

	// Legge gli elementi dal file fino al raggiungimento dell'end of file
	while(!feof(fptr)){

		fscanf(fptr,"%s\n",buffer);
		value = strtod(buffer, endPtr);

		if(endPtr != NULL){
		    fprintf(stderr,"Error: Strtod conversion\n");
		    exit(EXIT_FAILURE);
		}

		if(AppendNewNode(list, &value) == -1)
			exit(EXIT_FAILURE);
	}

	fclose(fptr);
}
