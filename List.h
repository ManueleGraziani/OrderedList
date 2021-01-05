// Definizione della struttura del nodo lista
struct listNode{
	double value;
	struct listNode *nextNode;
	struct listNode *preNode;
};

// Definizione della struttura dell'elemento lista
struct list{
	struct listNode *listHead;
	struct listNode *listTail;
	unsigned int listLen;
};

typedef struct listNode node;
typedef struct list list;

int AppendNewNode(list*, double*); // Aggiunge un nuovo nodo alla lista
void *GetNewNode(const double*);// Inizializza un nuovo nodo
void PrintList(list*);// Stampa la lista
void DeallocationList(list*);// Dealloca l'intera lista
