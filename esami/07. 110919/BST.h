#include "item.h"

typedef struct node *BST;

BST newBST(void);
int emptyBST(BST T);
item getItem(struct node *N);
struct node *getRoot(BST T);
BST figlioSX(BST T);
BST figlioDX(BST T);
BST insert(BST T, item elem);
int contains(BST T, item elem);
BST deleteNode(BST T, item elem);
void output_BST(BST T, int liv);

/*
1. constrAVL

specifica sintattica: constrAVL(BST, item*, int numel) -> BST
    dati di input: BST T, item a[], int numel
    dati di output: BST T'
specifica semantica:
    precondizione: a[] ha gli elementi in ordine crescente
    postcondizione: T' è l'AVL costruito con radice l'elemento mediano di a[] ecc ricorsivamente
*/
BST constrAVL(BST T, item a[], int numel);

/*
2. isAVL

specifica sintattica: isAVL(BST) -> boolean
    dati di input: BST T
    dati di output: boolean v
specifica semantica:
    postcondizione: se T è un AVL allora v = 1, altrimenti v = 0
*/
int altezza(BST T);
int isAVL(BST T);