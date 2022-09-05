//esame 150622
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
1. foglieK

progettazione
    1. passo base:
       1.1 se t è vuoto, restituisci 0
       1.2 se si arriva al livello k (k = 0), se t è una foglia restituisci 1
    2. passo ricorsivo: restituisci la somma di conta_fogliek sul figlio sx e sul figlio dx
*/

int conta_fogliek(Btree t, int k)
{
    if (emptyBtree(t))
    {
        return 0;
    }
    if (k == 0)
    {
        if (emptyBtree(figlioSX(t)) && emptyBtree(figlioDX(t)))
        {
            return 1;
        }
    }
    return conta_fogliek(figlioSX(t), k-1) + conta_fogliek(figlioDX(t), k-1);
}

/*
3. strutturalmenteSimili

progettazione
    1. passo base: 
        1.1 se gli alberi sono vuoti restituisci 1
        1.2 se i figli sx non sono entrambi vuoti o entrambi pieni, o se i figlio dx non sono entrambi vuoti
            o entrambi pieni, restituisci 0
    2. passo ricorsivo: verifica se figli sx e figli dx sono strutturalmente simili
*/

int strutturalmente_simili(Btree t1, Btree t2)
{
    if (emptyBtree(t1) && emptyBtree(t2))
    {
        return 1;
    }
    if (emptyBtree(figlioSX(t1)) != emptyBtree(figlioSX(t2)) || emptyBtree(figlioDX(t1)) != emptyBtree(figlioDX(t2)))
    {  
        return 0;
    }
    return strutturalmente_simili(figlioSX(t1), figlioSX(t2)) && strutturalmente_simili(figlioDX(t1), figlioDX(t2));
}

