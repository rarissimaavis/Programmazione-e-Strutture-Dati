//esame 010719
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

/*
1. cancFinoItem 
   data una coda Q e un item el, cancella da Q tutti gli item che precedono el 
   (se l’elemento el non è presente, vengono cancellati tutti gli item dalla coda)

2. fondiDaItem
   date 2 code Q1 e Q2 e un item el, inserisce in una nuova coda newQ gli elementi che a partire da el 
   sono contenuti sia in Q1 che in Q2 (se l’elemento el non è presente in entrambe le code, 
   oppure se a partire da el le due code non hanno elementi comuni, newQ risulterà vuota)
*/

int main(void)
{
    printf("esercizio 1: cancFinoItem\n"); 
    queue q;
    q = newQueue();
    q = input_queue(q);
    printf("coda: ");
    output_queue(q);

    q = cancFinoItem(q, 3);
    printf("\ncoda dopo aver cancellato gli elementi prima di 3: ");
    output_queue(q);
    
    printf("\nesercizio 2: fondiDaItem\n");
    queue q1, q2, new;
    q1 = newQueue();
    q2 = newQueue();
    new = newQueue();
    printf("coda 1\n");
    q1 = input_queue(q1);
    printf("coda 2\n");
    q2 = input_queue(q2);
    printf("\n coda 1: ");
    output_queue(q1);
    printf("\ncoda 2: ");
    output_queue(q2);

    new = fondiDaItem(q1, q2, 3);
    printf("\ncoda dopo fondi: ");
    output_queue(new);   
}