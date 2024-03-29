//esame 150622
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

PQueue input_PQ(int *a, int numel)
{
    PQueue pq = newPQ();
    for (int i = 0; i < numel; i++)
    {
        insert(pq, a[i]);
    }
    return pq;
}

void output_PQ(PQueue q) 
{
    for (int i = 1; i <= q->numel; i++) 
	{
        output_item(q->vet[i]);
    }
	printf("\n");
}

/*
2. PriorityQueueIncrease

progettazione
	1. crea una pqueue tmp
	2. assegna a max l'elemento di priorità massima di pq ed eliminalo da pq
	3. finchè pq non è vuota, inserisci il suo massimo in tmp ed eliminalo da pq
	4. finchè tmp non è vuota, inserisci il suo massimo+1 in pq ed eliminalo da tmp
	5. inserisci max in pq
	6. libera lo spazio occupato da tmp
*/

void pq_increase(PQueue pq)
{
	PQueue tmp = newPQ();
	item max = getMax(pq);
	deleteMax(pq);
	while (!emptyPQ(pq))
	{
		insert(tmp, getMax(pq));
		deleteMax(pq);
	}
	while (!emptyPQ(tmp))
	{
		insert(pq, getMax(tmp)+1);
		deleteMax(tmp);
	}
	insert(pq, max);
	free(tmp);
}

/*
void pq_increase(PQueue pq)
{
	for (int i = pq->numel; i > 1; i--)
	{
		pq->vet[i]++;
	}
}
*/