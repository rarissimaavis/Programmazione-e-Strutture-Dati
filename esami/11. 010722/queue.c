//esame 010722
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
2. canc

progettazione
	1. inserisci NULLITEM in q1
	2. finchè curr è diverso da NULLITEM, 
		2.1 assegna a curr il primo elemento della queue
		2.2 se curr è presente in q2, inseriscilo di nuovo in q1
	3. restituisci q1
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

queue canc(queue q1, queue q2)
{
	enqueue(NULLITEM, q1);
	item curr;
	while (curr != NULLITEM)
	{
		curr = dequeue(q1);
		if (presenteQ(q2, curr))
		{
			enqueue(curr, q1);
		}
	}
	return q1;
}
