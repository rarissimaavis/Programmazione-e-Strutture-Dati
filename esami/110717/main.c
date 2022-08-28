//esame 110717
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

/*
1. estraiMaxN
   data una coda Q e un intero n, estrae da Q, cancellandolo, il più grande fra i primi n elementi

2. inserMinN
   data una coda Q, un elemento el e un intero n, inserisce in Q l’elemento el subito prima del 
   più piccolo fra gli ultimi n elementi
*/

int main(void)
{
    queue q = newQueue();
    q = input_queue(q);
    printf("\ncoda: ");
    output_queue(q);

    printf("\n1. estraiMaxN");
    item max = maxn(q, 4);
    printf("\nmax: ");
    output_item(max);
    estraiMaxN(q, 4);
    printf("\ncoda dopo estrazione: ");
    output_queue(q);

    printf("\n2. inserMinN");
    item min = minn(q, 4);
    printf("\nmin: ");
    output_item(min);
    inserMinN(q, 9, 4);
    printf("\ncoda dopo inserimento: ");
    output_queue(q);
}