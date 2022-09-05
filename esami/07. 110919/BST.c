//esame 110919
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "item.h"
#include "BST.h"

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

BST newBST(void)
{
	return NULL;
}

int emptyBST(BST T)
{
	return T == NULL;
}

struct node *getRoot(BST T)
{
    return T;
}

BST figlioSX(BST T)
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

BST figlioDX(BST T)
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

int contains(BST T, item val)
{
	if (T == NULL)
	{
		return 0;
	}
	if (eq(val, getItem(T)))
	{
		return 1;
	}
	if (minore(val, getItem(T)))
	{
		return (contains(figlioSX(T), val));
	}
	else
	{
		return (contains(figlioDX(T), val));
	}
}

BST creaFoglia(item elem)
{
	struct node *N;
	N = malloc(sizeof(struct node));
	if (N == NULL)
	{
		return NULL;
	}
	setItem(N, elem);
	N->left = NULL;
	N->right = NULL;
	return N;
}

BST insert(BST T, item elem)
{
	if (T == NULL)
	{
		return creaFoglia(elem);
	}
	else
	{
		if (minore(elem, getItem(T)))
		{
			T->left = insert(T->left, elem);
		}
		else if (minore(getItem(T), elem))
		{
			T->right = insert(T->right, elem);
		}
	}
	return T;
}

struct node *minValue(struct node *node)
{
	struct node *current = node;
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

struct node *deleteNode(struct node *root, item key)
{
	if (root == NULL)
	{
		return root;
	}
	if (minore(key, root->value))
	{
		root->left = deleteNode(root->left, key);
	}
	else if (minore(root->value, key))
	{
		root->right = deleteNode(root->right, key);
	}
	else
	{
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		struct node *temp = minValue(root->right);
		root->value = temp->value;
		root->right = deleteNode(root->right, temp->value);
	}
	return root;
}

void output_BST(BST T, int liv)
{
    if (getRoot(T) == NULL) 
    {
	    return;
    }
    else 
    {
        output_BST(getRoot(T)->right, liv+1);
        for (int i = 0; i < liv; i++)
        {
    	    printf("   ");
        }
        printf("%d\n", getRoot(T)->value);
        output_BST(getRoot(T)->left, liv+1);
    }
}

/*
1. constrAVL

progettazione
	1. passo base: se il numero di elementi dell'array è 0 restituisci NULL
	2. inserisci l'elemento centrale di a come radice dell'albero
	3. passo ricorsivo:
		3.1 continua nel sottoalbero sinistro (fino a metà degli elementi dell'array)
		3.2 continua nel sottoalbero destro (vai all'elemento oltre la metà e se numel è pari assegna al nuovo
			valore la metà del valore precedente -1, se è dispari la metà)
	4. restituisci T
*/

BST constrAVL(BST T, item a[], int numel)
{
  	if (numel == 0)
  	{
    	return NULL;
  	}
  	T = insert(T, a[numel/2]);
  	constrAVL(T, a, numel/2);
  	if (numel%2 == 0)
  	{
    	constrAVL(T, &a[numel/2 + 1], numel/2 - 1);
  	}
  	else
  	{
		constrAVL(T, &a[numel/2 + 1], numel/2);
  	}
	return T;
}

/*
2. isAVL

progettazione
	1. passo base: se T è vuoto restituisci 1
	2. se la differenza in valore assoluto tra le altezze (funzione altezza) di figlio dx e sx è <= 1 e
	   (passo ricorsivo:) figlio sx e figlio dx sono AVL restituisci 1
	3. restituisci 0

raffinamento: funzione altezza
progettazione
	1. passo base: se T è vuoto restituisci 0
	2. passo ricorsivo: restituisci il massimo tra l'altezza del figlio dx e del figlio sx +1
*/

static int max(int n1, int n2) //un po' inutile lo so ma così altezza è meglio
{
	if (n1 > n2)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}

int altezza(BST T)
{
	if (emptyBST(T))
	{
		return 0;
	}
	return max(altezza(figlioSX(T)), altezza(figlioDX(T))) + 1;
}

int isAVL(BST T)
{
	if (emptyBST(T))
	{
		return 1;
	}
	int h_sx = altezza(figlioSX(T)), h_dx = altezza(figlioDX(T));
	if (abs(h_sx-h_dx) <= 1 && isAVL(figlioSX(T)) && isAVL(figlioDX(T)))
	{
		return 1;
	}
	return 0;
}

