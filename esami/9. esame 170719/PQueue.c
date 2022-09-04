//esame 170719
#include <stdio.h>
#include <stdlib.h>
#include "PQueue.h"
#define MAXPQ 50

struct c_PQ
{
	int vet[MAXPQ];
	int numel;
};

static void scendi(PQueue q);
static void sali(PQueue q);

PQueue newPQ(void)
{
	PQueue q;
	q = malloc(sizeof(struct c_PQ));
	if (q == NULL)
	{
		return NULL;
	}
	q->numel = 0;
	return q;
}

int emptyPQ(PQueue q)
{
	if (!q)
	{
		return 1;
	}
	return q->numel == 0;
}

PQueue input_PQ(int *a, int numel)
{
    PQueue pq = newPQ();
    for (int i = 0; i < numel; i++)
    {
        insert(pq, a[i]);
    }
    return pq;
}

int getMax(PQueue q)
{
	return q->vet[1];
}

int deleteMax(PQueue q)
{
	if (!q || q->numel == 0)
	{
		return 0;
	}
	q->vet[1] = q->vet[q->numel];
	q->numel--;
	scendi(q);
	return 1;
}

static void scendi(PQueue q)
{
	int temp, n = q->numel, i = 1, pos;
	while (1)
	{
		if (2*i+1 <= n)
		{
			pos = (q->vet[i*2] > q->vet[i*2+1])? i*2 : i*2+1;
		}
		else if (2*i <= n)
		{
			pos = 2*i;
		}
		else
		{
			break;
		}
		if (q->vet[pos] > q->vet[i])
		{
			temp = q->vet[i];
			q->vet[i] = q->vet[pos];
			q->vet[pos] = temp;
			i = pos;
		}
		else
		{
			break;
		}
	}
}

int insert(PQueue q, int key)
{
	if (!q || q->numel == MAXPQ) 
	{
		return 0;
	}
	q->numel++;
	q->vet[q->numel] = key;
	sali(q);
	return 1;
}

static void sali(PQueue q)
{
	int temp, pos = q->numel, i = pos/2;
	while (pos > 1)
	{
		if (q->vet[pos] > q->vet[i])
		{
			temp = q->vet[i];
			q->vet[i] = q->vet[pos];
			q->vet[pos] = temp;
			pos = i;
			i = pos/2;
		}
		else 
		{
			break;
		}
	}
}

void output_PQ(PQueue q) 
{
    for (int i = 1; i <= q->numel; i++) 
	{
        output_key(q->vet[i]);
    }
	printf("\n");
}

/*
1. estraiPriorK

progettazione
	1. crea lista l e Pqueue tmp
	2. finchè pq non è vuota, assegna il massimo a curr
		2.1 se curr è maggiore di k, inseriscilo nella lista l
		2. altrimenti inseriscilo in tmp
		3. eliminalo da pq
	3. finchè tmp non è vuota, inserisci il suo massimo in pq ed eliminalo
	4. restituisci l
*/

list estraiPriorK(PQueue pq, key k)
{
    list l = newList();
	PQueue tmp = newPQ();
	key curr;
	while (!emptyPQ(pq))
	{
		curr = getMax(pq);
		if (maggiore(curr, k))
		{
			l = consList(curr, l);
		}
		else
		{
			insert(tmp, curr);
		}
		deleteMax(pq);
	}
	while (!emptyPQ(tmp))
	{
		insert(pq, getMax(tmp));
		deleteMax(tmp);
	}
	return l;
}

/*
2. aumentaPrior

progettazione
	1. a partire dall'elemento di posizione numel fino alla radice (esclusa), sostitusci il valore 
	della key con quello della key del suo genitore (posizione i/2)
*/

void aumentaPrior(PQueue pq)
{
	for (int i = pq->numel; i > 1; i--)
	{
		pq->vet[i] = pq->vet[i/2];
	}
}
