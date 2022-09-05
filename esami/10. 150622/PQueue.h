#include "item.h"

typedef struct c_PQ *PQueue;

PQueue newPQ(void);
int emptyPQ(PQueue q);
int getMax(PQueue q);
int deleteMax(PQueue q);
int insert(PQueue q, int key);
PQueue input_PQ(int *a, int numel);
void output_PQ(PQueue q);

/*
specifica sintattica: pq_increase(priorityqueue)
    dati di input: PQueue pq
specifica semantica: 
    postcondizione: la priorità di tutti gli elementi escluso il primo è aumentata di 1
*/
void pq_increase(PQueue pq);