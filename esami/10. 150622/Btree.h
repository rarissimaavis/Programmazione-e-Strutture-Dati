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
specifica sintattica: conta_fogliek(Btree, int) -> int
    dati di input: Btree t, int k
    dati di output: int 
specifica semantica:
    postcondizione: la funzione restituisce il numero di foglie al livello k
*/
int conta_fogliek(Btree t, int k);

/*
specifica sintattica: strutturalmente_simili(Btree, Btree) -> boolean
    dati di input: Btree t1, Btree t2
    dati di output: boolean v
specifica semantica: 
    postcondizione: se t1 e t2 sono strutturalmente simili allora v = 1, altrimenti v = 0
*/
int strutturalmente_simili(Btree t1, Btree t2);

