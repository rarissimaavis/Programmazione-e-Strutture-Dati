//esame 050918
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "PQueue.h"

/*
1. listKeys
   data una PQ, restituisce la lista di tutte le chiavi in ordine di priorità, senza effettuare nessuna estrazione

2. remGreatestKeys
   data una PQ e un valore di chiave k, estrae dalla PQ tutti gli elementi con chiave maggiore o uguale a k
*/

int main(void)
{
    int a[9] = {100,19,36,17,3,25,1,2,7};
    PQueue pq = input_PQ(a, 9);
    printf("pq: ");
    output_PQ(pq);
    
    printf("\n1. listKeys\n");
    list l = listKeys(pq);
    outputList(l);

    printf("\n2. remGreatestKeys\n");
    remGreatestKeys(pq, 23);
    output_PQ(pq);
}
