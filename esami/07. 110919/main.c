//esame 110919
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "item.h"

/*
1. constrAVL
   dato un array A di n item ordinati in ordine crescente, costruisce un albero AVL che contiene gli n item
   (suggerimento: si proceda in modo simile alla ricerca binaria ricorsiva in un array, costruendo un albero 
   che ha come radice l’elemento mediano di A, e sottoalberi costruiti ricorsivamente con la parte sinistra 
   e con la parte destra di A, rispettivamente) 

2. isAVL
   dato un BST t, restituisce l’altezza di t se esso è un albero AVL, oppure -1 in caso contrario
*/

int main(void)
{
    int a[9] = {1,2,3,4,5,6,7,8,9}; //ordine crescente
    BST T;
    T = newBST();

    T = constrAVL(T,a,9);
    output_BST(T, 0);

    int v = isAVL(T);
    printf("\nè un AVL? %d\n", v);
}