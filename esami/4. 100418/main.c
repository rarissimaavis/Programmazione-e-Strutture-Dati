//esame 100418
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

/*
1. cancDaItem
   data una coda Q e un item el, cancella da Q tutti gli item che si trovano in posizioni successive a quella di el

2. fondiQueue
   date 2 code Q1 e Q2, inserisce in una nuova coda Q3 gli elementi che sono contenuti sia in Q1 che in Q2, senza ripetizioni
*/

int main(void)
{
    printf("1. cancDaItem\n");
    queue q = newQueue();
    q = input_queue(q);
    printf("\ncoda: ");
    output_queue(q);

    q = cancDaItem(q, 3);
    printf("coda dopo aver cancellato gli elementi dopo 3: ");
    output_queue(q);

    printf("\n2. fondiQueue\n");
    queue q1 = newQueue();
    printf("coda 1\n");
    q1 = input_queue(q1);
    queue q2 = newQueue();
    printf("coda 2\n");
    q2 = input_queue(q2);
    queue q3 = newQueue();
    printf("\ncoda 1: ");
    output_queue(q1);
    printf("coda 2: ");
    output_queue(q2);

    q3 = fondiQueue(q1, q2);
    printf("coda fusa (amo noi): ");
    output_queue(q3);
}