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
specifica sintattica: listKeys(priorityqueue) -> list
    dati di input: PQueue pq
    dati di output: list l
specifica semantica:
    precondizione: non devono essere effettuate estrazioni 
    postcondizione: l contiene le chiavi di pq in ordine di priorità
*/
list listKeys(PQueue pq);

/*
specifica sintattica: remGreatestKeys(priorityqueue, key)
    dati di input: PQueue pq, key k
specifica semantica:
    postcondizione: da pq vengono rimosse le key >= k
*/
void remGreatestKeys(PQueue pq, key k);
