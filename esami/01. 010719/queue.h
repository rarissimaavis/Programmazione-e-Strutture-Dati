#include "item.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
queue input_queue(queue q);
int enqueue(item val, queue q);
item dequeue(queue q);
void output_queue(queue q);

/*
1. cancFinoItem

specifica sintattica: cancFinoItem(queue, item) -> queue
    dati di input: queue q, item el
    dati di output: queue q'
specifica semantica:
    postcondizione: q' contiene gli elementi di q a partire da el
*/
queue cancFinoItem(queue q, item el);

/*
1. fondiDaItem

specifica sintattica: fondiDaItem(queue, queue, item) -> queue
    dati di input: queue q1, queue q2, item el
    dati di output: queue newQ
specifica semantica:
    precondizione: no doppie perchè non so come gestirle
    postcondizione: newQ contiene gli elementi comuni a q1 e q2 successivi a el
*/
queue fondiDaItem(queue q1, queue q2, item el);