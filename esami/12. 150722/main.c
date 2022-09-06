//esame 150722
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"
#include "stack.h"

/*
1. contare i figli unici di un albero

2. dati due stack inserire il secondo stack al centro del primo (il secondo stack deve rimanere invariato)
*/

int main(void)
{
    int a[8] = {100,19,36,17,3,25,1,2};
    Btree t = newBtree();
    t = input_Btree(a, 0, 8);
    output_Btree(t, 0);

    printf("\n1. conta figli unici: %d\n", conta_figli_unici(t));

    printf("\n2. stack al centro: \n");
    stack s1 = newStack(), s2 = newStack();
    printf("stack 1\n");
    s1 = input_stack(s1);
    printf("stack 2\n");
    s2 = input_stack(s2);

    s1 = al_centro(s1, s2);
    printf("\ns2 al centro di s1: ");
    output_stack(s1);
}
