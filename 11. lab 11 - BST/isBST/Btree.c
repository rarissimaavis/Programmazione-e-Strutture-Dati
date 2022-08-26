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

int min_Btree(Btree T)
{
    int min, minSX, minDX;
    if (emptyBtree(T))
    {
        return 2147483647;
    }
    min = getItem(getRoot(T));
    minSX = min_Btree(figlioSX(T));
    minDX = min_Btree(figlioDX(T));
    if (min < minSX && min < minDX)
    {
        return min;
    }
    else if (minSX < minDX)
    {
        return minSX;
    }
    else if (minDX < minSX)
    {
        return minDX;
    }
}

int max_Btree(Btree T)
{
    int max, maxSX, maxDX;
    if (emptyBtree(T))
    {
        return -2147483648;
    }
    max = getItem(getRoot(T));
    maxSX = max_Btree(figlioSX(T));
    maxDX = max_Btree(figlioDX(T));
    if (max > maxSX && max > maxDX)
    {
        return max;
    }
    else if (maxSX > maxDX)
    {
        return maxSX;
    }
    else if (maxDX > maxSX)
    {
        return maxDX;
    }
}