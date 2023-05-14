#include "item.h"

typedef struct node *BST;

/*
specifica sintattica:
    newBST: () -> bst
specifica semantica:
    postcondizione: T = albero vuoto
*/
BST newBST(void);

/*
specifica sintattica:
    emptyBST: (bst) -> boolean
specifica semantica:
    postcondizione: se T è vuoto allora v = vero, altrimenti v = falso
*/
int emptyBST(BST T);

item getItem(struct node *N);

struct node *getRoot(BST T);

/*
specifica sintattica:
    figlioSX: (bst) -> bst
specifica semantica:
    precondizione: T = <N, Tsx, Tdx> non è l'albero vuoto
    postcondizione: T' = Tsx
*/
BST figlioSX(BST T);

/*
specifica sintattica:
    figlioDX: (bst) -> bst
specifica semantica:
    precondizione: T = <N, Tsx, Tdx> non è l'albero vuoto
    postcondizione: T' = Tdx
*/
BST figlioDX(BST T);

/*
specifica sintattica:
    insert: (bst, item) -> bst
specifica semantica:
    postcondizione: 
*/
BST insert(BST T, item elem);

/*
specifica sintattica:
    contains: (bst, item) -> boolean
specifica semantica:
    postcondizione: se elem è contenuto in T allora v = vero, altrimenti v = falso
*/
int contains(BST T, item elem);

/*
specifica sintattica:
    deleteNode: (bst, item) -> bst
specifica semantica:
    postcondizione:
*/
BST deleteNode(BST T, item elem);

void output_BST(BST T, int liv);