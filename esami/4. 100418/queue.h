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
1. cancDaItem
specifica sintattica: cancDaItem(queue, item) -> queue
    dati di input: queue q, item el
    dati di output: queue q'
specifica semantica:
    postcondizione: q' non contiene gli elementi successivi ad el
*/
queue cancDaItem(queue q, item el);

/*
2. fondiQueue
specifica sintattica: fondiQueue(queue, queue) -> queue
    dati di input: queue q1, queue q2
    dati di output: queue q3
specifica semantica: 
    postcondizione: q3 contiene gli elementi che sono contenuti sia in q1 che in q2 (senza ripetizioni)
*/
queue fondiQueue(queue q1, queue q2);