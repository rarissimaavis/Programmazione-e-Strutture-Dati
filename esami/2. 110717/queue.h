#include "item.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
queue input_queue(queue q);
int enqueue(item val, queue q);
item dequeue(queue q);
int size_queue(queue q);
void output_queue(queue q);

/*
1. estraiMaxN
specifica sintattica: estraiMaxN(queue, int) -> queue
    dati di input: queue q, int n
    dati di output: queue q'
specifica semantica:
    postcondizione: q' non contiene il più grande tra i primi n elementi di q
*/
item maxn(queue q, int n);
queue estraiMaxN(queue q, int n);

/*
2. inserMinN
specifica sintattica: inserMinN(queue, item, int) -> queue
    dati di input: queue q, item el, int n
    dati di output: queue q'
specifica semantica:
    postcondizione: q' contiene el prima del più piccolo tra gli ultimi elmenti di n
*/
item minn(queue q, int n);
queue inserMinN(queue q, item el, int n);