//esame 170619
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

/*
1. presenteQ
   data una coda Q e un item el, verifica se el è presente in Q

2. xorQ
   date due code Q1 e Q2, costruisce una nuova coda Q’ contenente gli elementi che sono presenti 
   in Q1 oppure in Q2, ma non in entrambe (unione disgiunta)
*/

int main(void)
{
    printf("1. presenteQ\n");
    queue q = newQueue();
    q = input_queue(q);
    printf("\ncoda: ");
    output_queue(q);
    
    int presente = presenteQ(q, 3);
    printf("\n3 è presente in q? %d\n", presente);

    printf("\n2. xorQ\ncoda 1\n");
    queue q1 = newQueue();
    q1 = input_queue(q1);
    printf("\ncoda 2\n");
    queue q2 = newQueue();
    q2 = input_queue(q2);
    printf("\ncoda 1: ");
    output_queue(q1);
    printf("\ncoda 2: ");
    output_queue(q2);

    queue xor = newQueue();
    xor = xor_queue(q1, q2);
    printf("\nxor di q1 e q2: ");
    output_queue(xor);
    
}