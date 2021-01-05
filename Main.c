#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "File.h"
#include "Sort.h"

static double __ReturnVal(const list*, const char*);

// Acces point
int main(int argc, char *argv[]){

    // Inizializzazione dell'elemento lista
	list list = {.listHead = NULL, .listTail = NULL, .listLen = 0};

	// Controllo dell'input utente
	if(argc < 3){
		fprintf(stderr,"Error: sintassi errata\n"
				"Digitare %s [FILE PATH] [NUMBER]\n",*argv);
		exit(EXIT_FAILURE);
	}

	/*
	 * La funzione ReadFromFile legge i valori dal file linkato dall'utente,
	 * passandoli come parametri alla funzione AppendNewNode.
	 */
	ReadFromFile(argv[1],&list);
	printf("Numero dei nodi: [%d]\n",list.listLen);

	// Ordina gli elementi della lista in modo crescente
	MergeSort(&list);

    puts("Lista Ordinata");
	PrintList(&list);


	return __ReturnVal(&list, argv[2]);
}

static double __ReturnVal(const list *list, const char *argv ){

    char **endPtr = NULL;
    unsigned int i, id = (unsigned int) strtod(argv,endPtr);
    node *curNode = list->listHead;

    if(endPtr != NULL){
        fprintf(stderr,"Error: Strtod conversion\n");
        exit(EXIT_FAILURE);
    }

    if(id > list->listLen){

        fprintf(stderr,"Error: La posizione del valore richiesto supera la dimensione della lista\n");
        exit(EXIT_FAILURE);

    }else {

        for (i = 1; i < id; i++) {
            curNode = curNode->nextNode;
        }

    }

    return round(curNode->value);
}