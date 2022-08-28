//esame 010719
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

struct node
{
    item value;
    struct node *next;
};

struct c_queue
{
	struct node *head, *tail;
	int numel;
};

queue input_queue(queue q)
{
    int x;
    input_item(&x);
    while (x != -1)
    {
        enqueue(x, q);
        input_item(&x);
    }
    return q;
}

queue newQueue(void)
{
	struct c_queue *q;
	q = malloc(sizeof(struct c_queue));
	if (q == NULL)
	{
		return NULL;
	}
	q->numel = 0;
	q->head = NULL;
	q->tail = NULL;
	return q;
}

int emptyQueue(queue q)
{
	if (q == NULL)
	{
		return -1;
	}
	return q->numel == 0;
}

int enqueue(item val, queue q)
{
	if (q == NULL)
	{
		return -1;
	}
	struct node *nuovo;
	nuovo = malloc(sizeof(struct node));
	if (nuovo == NULL)
	{
		return 0;
	}
	nuovo->value = val;
	nuovo->next = NULL;
	if (q->head == NULL)
	{
		q->head = nuovo;
	}
	else
	{
		q->tail->next = nuovo;
	}
	q->tail = nuovo;
	(q->numel)++; 
	return 1;
}

item dequeue(queue q)
{
	if (q == NULL)
	{
		return NULLITEM;
	}
	if (q->numel == 0)
	{
		return NULLITEM;
	}
	item result = q->head->value;
	struct node *temp = q->head;
	q->head = q->head->next;
	free(temp);
	if (q->head == NULL)
	{
		q->tail == NULL;
	}
	(q->numel)--;
	return result;
}

void output_queue(queue q)
{
    struct node *t;
    t = q->head;
    while (t)
    {
        output_item(t->value);
        t = t->next;
    }
	printf("\n");
}

/*
1. cancFinoItem

progettazione
	1. finchè q non è vuota e il primo elemento è diverso da el, eliminalo
	2. restituisci q
*/

queue cancFinoItem(queue q, item el)
{
	while (!emptyQueue(q) && !eq(q->head->value, el))
	{
		dequeue(q);
	}
	return q;
}

/*
2. fondiDaItem

progettazione
	1. crea nodi p1 e p2 e alloca lo spazio necessario
	2. crea queue newQ
	3. cancella gli elementi precedenti a el da q1 e da q2
	4. elimina el (se c'è) da q1 e da q2
	5. assegna a p1 il valore head di q1
	6. finchè c'è un elemento p1, 
		6.1 assegna a p2 il valore head di q2
		6.2 finchè c'è un elemento p2, 
			6.2.1 se i valori di p1 e p2 sono uguali, inserisci il valore di p1 in newQ
			6.2.2 aggiorna il valore di p2 con l'elemento successivo
		6.3 aggiorna il valore di p1 con l'elemento successivo
	7. libera lo spazio occupato da p1 e p2
	8. restituisci newQ
*/

queue fondiDaItem(queue q1, queue q2, item el)
{
	struct node *p1, *p2;
	queue newQ = newQueue();
	p1 = malloc(sizeof(struct node));
	p2 = malloc(sizeof(struct node));
	if (p1 == NULL || p2 == NULL)
	{
		return NULL;
	}
	q1 = cancFinoItem(q1, el);
	q2 = cancFinoItem(q2, el);
	dequeue(q1);
	dequeue(q2);
	p1 = q1->head;
	while (p1)
	{
		p2 = q2->head;
		while (p2)
		{
			if (eq(p1->value, p2->value))
			{
				enqueue(p1->value, newQ);
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	free(p1);
	free(p2);
	return newQ;
}