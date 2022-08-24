#include "item.h"

typedef struct node *Btree;

/*
specifica sintattica:
    newBtree: () -> alberobin
specifica semantica:
    postcondizione: T = albero vuoto
*/
Btree newBtree(void);

/*
specifica sintattica:
    emptyBtree: (alberobin) -> boolean
specifica semantica:
    postcondizione: se T è vuoto allora v = vero, altrimenti v = falso
*/
int emptyBtree(Btree T);

/*
specifica sintattica:
    getItem: (nodo) -> item
specifica semantica:
    postcondizione: N' = N->value
*/
item getItem(struct node *N);

/*
specifica sintattica:
    getRoot: (alberobin) -> nodo
specifica semantica:
    precondizione: T = <N, Tsx, Tdx> non è l'albero vuoto
    postcondizione: N = N'
*/
struct node *getRoot(Btree T);

/*
specifica sintattica:
    consBtree(item, alberobin, alberobin) -> alberobin
specifica semantica:
    precondizione: elem != NULLITEM
    postcondizione: T' = <N, T1, T2>, N è un nodo con etichetta elem
*/
Btree consBtree(item val, Btree sx, Btree dx);

/*
specifica sintattica:
    figlioSX: (alberobin) -> alberobin
specifica semantica:
    precondizione: T = <N, Tsx, Tdx> non è l'albero vuoto
    postcondizione: T' = Tsx
*/
Btree figlioSX(Btree T);

/*
specifica sintattica:
    figlioDX: (alberobin) -> alberobin
specifica semantica:
    precondizione: T = <N, Tsx, Tdx> non è l'albero vuoto
    postcondizione: T' = Tdx
*/
Btree figlioDX(Btree T);

void output_Btree(Btree T, int liv);

