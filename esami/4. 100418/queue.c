//esame 100418
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
1. cancDaItem

progettazione
	1. inserisci in q NULLITEM
	2. assegna a curr il primo elemento di q
	3. finchè curr è diverso da NULLITEM e diverso da el, inserisci curr in q e aggiorna curr
	4. se curr è uguale ad el inseriscilo in q
	5. finchè curr è diverso da NULLITEM elimina gli elementi di q
	6. restituisci q
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

queue cancDaItem(queue q, item el)
{
	enqueue(NULLITEM, q);
	item curr = dequeue(q);
	while (curr != NULLITEM && !eq(curr, el))
	{
		enqueue(curr, q);
		curr = dequeue(q);
	}
	if (eq(curr, el))
	{
		enqueue(curr, q);
	}
	while (curr != NULLITEM)
	{
		curr = dequeue(q);
	}
	return q;
}

/*
2. fondiQueue

progettazione
	1. crea la nuova queue q3
	2. inserisci NULLITEM in q1 
	3. assegna a curr il primo elemento di q1
	4. finchè curr è diverso da NULLITEM, 
		4.1 se curr è presente in q2 e non è ancora presente in q3, inseriscilo in q3
		4.2 inserisci curr in q1
		4.3 aggiorna curr con il primo elemento di q1
	5. restituisci q3
*/

queue fondiQueue(queue q1, queue q2)
{
	queue q3 = newQueue();
	enqueue(NULLITEM, q1);
	item curr = dequeue(q1);
	while (curr != NULLITEM)
	{
		if (presenteQ(q2, curr) && !presenteQ(q3, curr))
		{
			enqueue(curr, q3);
		}
		enqueue(curr, q1);
		curr = dequeue(q1);
	}
	return q3;
}