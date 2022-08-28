//esame 170619
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

int size_queue(queue q)
{
	return q->numel;
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
1. presenteQ

progettazione
	1. inizializza  va 0
	2. inserisci NULLITEM in q
	2. assegna a curr il primo elemento della queue
	3. fichè curr è diverso da NULLITEM,
		3.1 se curr è uguale ad el, aggiorna il valore di v ad 1
		3.2 inserisci curr in q
		3.3 aggiorna il valore di curr con il primo elemento della queue
	4. restituisci v 
*/

int presenteQ(queue q, item el)
{
	int v = 0;
	enqueue(NULLITEM, q);
	item curr = dequeue(q);
	while (curr != NULLITEM)
	{
		if (curr == el)
		{
			v = 1;
		}
		enqueue(curr, q);
		curr = dequeue(q);
	}
	return v;
}

/*
1. 

progettazione
	1. assegna a curr1 il primo elemento di q1
	2. inserisci NULLITEM in q1
	3. finchè curr1 è diverso da NULLITEM,
		3.1 se curr1 non è presente in q2 (funzione presenteQ), inseriscilo in new
		3.2 inserisci curr1 in q1
		3.3 aggiorna curr1 con il primo elemento di q1
	4. stesso procedimento a partire da q2
	5. restituisci new
*/

queue xor_queue(queue q1, queue q2)
{
	queue new = newQueue();
	item curr1 = dequeue(q1);
	enqueue(NULLITEM, q1);
	while (curr1 != NULLITEM)
	{
		if (!presenteQ(q2, curr1))
		{
			enqueue(curr1, new);
		}
		enqueue(curr1, q1);
		curr1 = dequeue(q1);
	}
	item curr2 = dequeue(q2);
	enqueue(NULLITEM, q2);
	while (curr2 != NULLITEM)
	{
		if (!presenteQ(q1, curr2))
		{
			enqueue(curr2, new);
		}
		enqueue(curr2, q2);
		curr2 = dequeue(q2);
	}
	return new;
}
