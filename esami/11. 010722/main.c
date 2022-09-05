//esame 010722
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"
#include "queue.h"

/*
1. contare i figli sinistri di un albero

2. date due code, eliminare dalla coda 1 gli elementi che non sono presenti nella coda 2
*/

int main(void)
{
    int a[8] = {100,19,36,17,3,25,1,2};
    Btree t = newBtree();
    t = input_Btree(a, 0, 8);
    output_Btree(t, 0);

    printf("\n1. conta figli sinistri: %d\n", conta_figli_sx(t));

    printf("\n2. canc da queue: \n");
    queue q1 = newQueue(), q2 = newQueue();
    q1 = input_queue(q1);
    q2 = input_queue(q2);

    q1 = canc(q1, q2);
    output_queue(q1);
}
