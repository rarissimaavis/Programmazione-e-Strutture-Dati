#include "list.h"
#include "item.h"

typedef struct c_PQ *PQueue;

PQueue newPQ(void);
int emptyPQ(PQueue q);
PQueue input_PQ(int *a, int numel);
int getMax(PQueue q);
int deleteMax(PQueue q);
int insert(PQueue q, int key);
void output_PQ(PQueue q);

/*
specifica sintattica: estraiPriorK(priorityqueue, key) -> list
    dati di input: PQueue pq, key k
    dati di output: list l
specifica semantica:
    postcondizione: gli elementi con key >= k vengono rimossi da pq e inseriti in l
*/
list estraiPriorK(PQueue pq, key k);

/*
specifica sintattica: aumentaPrior(priorityqueue)
    dati di input: PQueue pq
specifica semantica: 
    postcondizione: ogni elemento (tranne la radice) ha la key del suo genitore
*/
void aumentaPrior(PQueue pq);
