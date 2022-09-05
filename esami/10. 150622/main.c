//esame 150622
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"
#include "PQueue.h"

/*
1. Fogliek(Btree T, int k)
   La funzione conta il numero di foglie (se presenti) al livello k, restituendolo

2. void PriorityQueueIncrease(Pqueue q)
   La funzione incrementa di 1 la priorità di tutti gli elementi ESCLUSO il primo. 
   La coda q (a fine esecuzione) deve contenere il primo elemento + tutti gli altri elementi con priorità +1.

3. BOOL strutturalmenteSimili(Btree T1, Btree T2)
   Restituisce true (1) o false (0) se gli alberi sono o meno strutturalmente simili
*/

int main(void)
{
    int a[9] = {100,19,36,17,3,25,1,2,7};
    Btree t = newBtree();
    t = input_Btree(a, 0, 9);
    output_Btree(t, 0);

    printf("\n1. conta foglie k: %d\n", conta_fogliek(t, 2));

    printf("\n2. pq increase: ");
    PQueue pq = input_PQ(a, 9);
    pq_increase(pq);
    output_PQ(pq);

    printf("\n3. strutturalmente simili: ");
    Btree t1 = newBtree(), t2 = newBtree();
    t1 = input_Btree(a, 0, 9);
    int b[9] = {1,2,3,4,5,6,7,8,9};
    t2 = input_Btree(b, 0, 9);
    printf("%d\n", strutturalmente_simili(t1, t2));
}
