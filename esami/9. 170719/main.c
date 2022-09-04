//esame 170719
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "PQueue.h"

/*
1. estraiPriorK(HEAP, k) 
   estrae da HEAP tutti gli elementi con chiave avente priorità maggiore o uguale a quella della chiave k,
   mettendoli in una lista, che viene restituita come risultato

2. aumentaPrior(HEAP) 
   in maniera bottom-up assegna a ciascun elemento, escluso la radice, la stessa priorità del suo genitore
*/

int main(void)
{
    int a[9] = {100,19,36,17,3,25,1,2,7};
    PQueue pq = input_PQ(a, 9);
    printf("pq: ");
    output_PQ(pq);

    printf("\n1. estraiPriorK\n");
    list l = estraiPriorK(pq, 33);
    outputList(l);
    output_PQ(pq);

    printf("\n1. aumentaPrior: ");
    aumentaPrior(pq);
    output_PQ(pq);
}
