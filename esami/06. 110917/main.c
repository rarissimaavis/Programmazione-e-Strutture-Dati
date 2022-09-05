//esame 110917
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

/*
1. cancFinoItem
   data una lista L e un item el, cancella da L tutti gli item che si trovano in posizioni precedenti a quella di el

2. fondiDaItem
   date 2 liste L1 e L2 e un item el, inserisce in una nuova lista newLista gli elementi che a partire da el 
   sono contenuti sia in L1 che in L2
*/

int main (void)
{
    printf("1. cancDaItem\n");
    list l = newList();
    l = input_list(l);
    printf("\nlista:\n");
    outputList(l);

    l = cancFinoItem(l, 3);
    printf("\nlista dopo canc: \n");
    outputList(l);

    printf("\n2. fondiDaItem\n");
    list l1 = newList(), l2 = newList(), l3 = newList();
    l1 = input_list(l1);
    l2 = input_list(l2);

    l3 = fondiDaItem(l1, l2, 3);
    printf("\nlista dopo fondi: \n");
    outputList(l3);
    return 0;
}
