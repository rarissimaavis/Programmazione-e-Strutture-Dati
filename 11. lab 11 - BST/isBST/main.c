#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"
#include "item.h"

Btree input_Btree(int *a, int i, int numel)
{
    if (i >= numel)
    {
        return NULL;
    }
    return consBtree(a[i], input_Btree(a, 2*i+1, numel), input_Btree(a, 2*i+2, numel));
}

/*
1. è di ricerca?
   Dato un albero binario BTree, scrivere una funzione che attraverso la restituzione di un valore booleano 
   verifichi che esso sia un albero binario di ricerca. bool isBST(BTree tree)

specifica
    dati di input: Btree T
    dati di output: boolean
    precondizione: l'albero deve esistere
    postcondizione: se T è un BST allora v = 1, altrimenti v = 0

progettazione
    1. passo base: se l'albero è vuoto restituisci 1
    2. se il massimo valore del sottoalbero sinistro è maggiore della radice e il minimo valore del sottoalbero
       destro è minore della radice restituisci 0
    3. passo ricorsivo: se il sottoalbero sinistro e il sottoalbero destro sono BST restituisci 1
    4. restituisci 0
*/

int isBST(Btree T)
{
    if (emptyBtree(T))
    {
        return 1;
    }
    int maxSX = max_Btree(figlioSX(T));
    int minDX = min_Btree(figlioDX(T));
    int root = getItem(getRoot(T));
    if (maxSX > root || minDX < root)
    {
        return 0;
    }
    if (isBST(figlioSX(T)) && isBST(figlioDX(T)))
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    int v;
    int a[7] = {10,6,18,4,8,15,21};
    
    Btree T;
    T = newBtree();
    T = input_Btree(a, 0, 7);
    printf("albero: \n");
    output_Btree(T, 0);
    
    v = isBST(T);
    printf("\nè di ricerca? %d\n", v);
}