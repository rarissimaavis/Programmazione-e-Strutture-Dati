#include "item.h"

typedef struct c_PQ *PQueue;

/*
specifica sintattica:
    newPQ: () -> priorityqueue
specifica semantica:
    postcondizione: PQ = /\ (coda vuota)
*/
PQueue newPQ(void);

/*
specifica sintattica:
    emptyPQ: (priorityqueue) -> boolean
specifica semantica:
    postcondizione: se PQ è vuota allora v = vero, altrimenti v = falso
*/
int emptyPQ(PQueue q);

/*
specifica sintattica:
    getMax: (priorityqueue) -> item
specifica semantica:
    precondizione: PQ non è vuota
    postcondizione: elem è la entry con la massima priorità fra quelle contenute in PQ
*/
int getMax(PQueue q);

/*
specifica sintattica:
    deleteMax: (priorityqueue) -> priorityqueue
specifica semantica:
    precondizione: PQ non è vuota
    postcondizione: PQ' contiene tutte le entry di PQ tranne quelle con massima priorità
*/
int deleteMax(PQueue q);

/*
specifica sintattica:
    insertPQ: (priorityqueue, item) -> priorityqueue
specifica semantica:
    postcondizione: PQ' contiene elem e tutte le entry contenute in PQ
*/
int insert(PQueue q, int key);

PQueue input_PQ(int *a, int numel);

void output_PQ(PQueue q);