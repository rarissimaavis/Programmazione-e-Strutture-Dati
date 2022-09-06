//esame 150722
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"

struct node
{
    item value;
    struct node *left;
    struct node *right;
};

item getItem(struct node *N)
{
    if (N == NULL)
    {
        return NULLITEM;
    }
    return N->value;
}

void setItem(struct node *N, item el)
{
    if (N == NULL)
    {
        return;
    }
    N->value = el;
}

Btree newBtree(void)
{
    return NULL;
}

int emptyBtree(Btree T)
{
    return T == NULL;
}

struct node *getRoot(Btree T)
{
    return T;
}

Btree consBtree(item val, Btree sx, Btree dx)
{
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo != NULL)
    {
        setItem(nuovo, val);
        nuovo->left = sx;
        nuovo->right = dx;
    }
    return nuovo;
}

Btree figlioSX(Btree T)
{
    if (T != NULL)
    {
        return T->left;
    }
    else
    {
        return NULL;
    }
}

Btree figlioDX(Btree T)
{
    if (T != NULL)
    {
        return T->right;
    }
    else
    {
        return NULL;
    }
}

void output_Btree(Btree T, int liv)
{
    if (getRoot(T) == NULL) 
    {
	    return;
    }
    else 
    {
        output_Btree(getRoot(T)->right, liv+1);
        for (int i = 0; i < liv; i++)
        {
    	    printf("   ");
        }
        printf("%d\n", getRoot(T)->value);
        output_Btree(getRoot(T)->left, liv+1);
    }
}

Btree input_Btree(int *a, int i, int numel)
{
    if (i >= numel)
    {
        return NULL;
    }
    return consBtree(a[i], input_Btree(a, 2*i+1, numel), input_Btree(a, 2*i+2, numel));
}

/*
1. conta figli unici

progettazione
    1. passo base: 
        1.1 se t è vuoto restituisci 0
        1.2 se t ha un solo figlio
    2. passo ricorsivo: restituisci la somma dei figli unici del sottoalbero sx e del sottoalbero dx
*/

int conta_figli_unici(Btree t)
{
    if (emptyBtree(t))
    {
        return 0;
    }
    if ((!emptyBtree(figlioSX(t)) && emptyBtree(figlioDX(t))) || (emptyBtree(figlioSX(t)) && !emptyBtree(figlioDX(t))))
    {
        return 1;
    }
    return conta_figli_unici(figlioSX(t)) + conta_figli_unici(figlioDX(t));
}