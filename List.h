// Definizione del nodo
struct listNode{
	unsigned int id;
	double value;
	struct listNode *nextNode;
	struct listNode *preNode;
};

struct list{
	struct listNode *listHead;
	struct listNode *listTail;
	unsigned int listLen;

};

typedef struct listNode node;
typedef struct list list;

void *GetNewNode(unsigned int, double*);
int AppendNewNode(list*, double*);
void PrintList(list*);
