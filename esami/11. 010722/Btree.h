#include "item.h"

typedef struct node *Btree;

Btree newBtree(void);
int emptyBtree(Btree T);
item getItem(struct node *N);
struct node *getRoot(Btree T);
Btree consBtree(item val, Btree sx, Btree dx);
Btree figlioSX(Btree T);
Btree figlioDX(Btree T);
void output_Btree(Btree T, int liv);
Btree input_Btree(int *a, int i, int numel);

/*
specifica sintattica: conta_figli_unici(Btree) -> int
    dati di input: Btree t
    dati di output: int 
specifica semantica:
    postcondizione: restituisce il numero di figli sinistri presenti in t
*/
int conta_figli_sx(Btree t);

