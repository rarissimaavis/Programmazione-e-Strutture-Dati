//esame 110717
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
1. estraiMaxN

progettazione
	1. assegna a max il massimo dei primi n elementi di q (funzione maxn)
	2. assegna a curr il primo elemento della queue
	3. inserisci NULLITEM in q
	4. finchè l'elemento orrente è diverso da NULLITEM (arrivo alla fine della queue iniziale), 
		4.1 se curr è uguale a max, aggiorna il valore di curr con il primo elemento della queue
			(in modo da eliminare il max)
		4.1 inserisci curr in q
		4.2 aggiorna il valore di curr con il primo elemento della queue
	5. restituisci q

raffinamento: funzione maxn
progettazione
	1. assegna a curr e a max il primo elemento della queue
	2. inserisci NULLITEM in q
	3. scorri gli elementi di q a partire dal secondo (il primo è già in curr) fino ad n,
		3.1 se curr è maggiore del massimo attuale, aggiorna il valore di max con curr
		3.2 inserisci curr in q
		3.3 aggiorna il valore di curr con il primo elemento della queue
	4. finchè curr è diverso da NULLITEM,
		4.1 inserisci curr in q
		4.2 aggiorna il valore di curr con il primo elemento della queue
	5. restituisci max
*/

item maxn(queue q, int n)
{
	item curr = dequeue(q);
	item max = curr;
	enqueue(NULLITEM, q);
	for (int i = 1; i <= n; i++)
	{
		if (curr > max)
		{
			max = curr;
		}
		enqueue(curr, q);
		curr = dequeue(q);
	}
	while (curr != NULLITEM)
	{
		enqueue(curr, q);
		curr = dequeue(q);
	}
	return max;
}

queue estraiMaxN(queue q, int n)
{
	item max = maxn(q, n);
	item curr = dequeue(q);
	enqueue(NULLITEM, q);
	while (curr != NULLITEM)
	{
		if (curr == max)
		{
			curr = dequeue(q);
		}
		enqueue(curr, q);
		curr = dequeue(q);
	}
	return q;
}

/*
1. estraiMaxN

progettazione
	1. assegna a min il massimo dei primi n elementi di q (funzione maxn)
	2. assegna a curr il primo elemento della queue
	3. inserisci NULLITEM in q
	4. finchè l'elemento orrente è diverso da NULLITEM (arrivo alla fine della queue iniziale), 
		4.1 inserisci curr in q
		4.2 aggiorna il valore di curr con il primo elemento della queue
		4.3 se curr è uguale a min, inserisci el in q
	5. restituisci q

raffinamento: funzione minn
progettazione
	1. assegna a curr il primo elemento della queue
	2. inserisci NULLITEM in q
	3. scorri gli elementi di q fino all'elemento di posizione size-n,
		3.1 inserisci curr in q
		3.2 aggiorna il valore di curr con il primo elemento della queue
	4. assegna a min il primo elemento della queue
	5. finchè curr è diverso da NULLITEM,
		5.1 se curr è minore del minimo attuale, aggiorna il valore di min con curr
		5.2 inserisci curr in q
		5.3 aggiorna il valore di curr con il primo elemento della queue
	6. restituisci min
*/

item minn(queue q, int n)
{
	item curr = dequeue(q);
	enqueue(NULLITEM, q);
	for (int i = 0; i < size_queue(q)-n; i++)
	{
		enqueue(curr, q);
		curr = dequeue(q);
	}
	item min = curr;
	while (curr != NULLITEM)
	{
		if (curr < min)
		{
			min = curr;
		}
		enqueue(curr, q);
		curr = dequeue(q);
	}
	return min;
}

queue inserMinN(queue q, item el, int n)
{
	item min = minn(q, n);
	item curr = dequeue(q);
	enqueue(NULLITEM, q);
	while (curr != NULLITEM)
	{
		enqueue(curr, q);
		curr = dequeue(q);
		if (curr == min)
		{
			enqueue(el, q);
		}
	}
	return q;
}