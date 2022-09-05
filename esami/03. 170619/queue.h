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
1. 
specifica sintattica: presenteQ(queue, item) -> boolean
    dati di input: queue q, item el
    dati di output: boolean v
specifica semantica: 
    postcondizione: se el è presente in q allora v = 1, altrimenti v = 0
*/
int presenteQ(queue q, item el);

/*
2. 
specifica sintattica: 
    dati di input: queue q1, queue q2
    dati di output: queue q'
specifica semantica:
    postcondizione: q' contiene gli elementi presenti in q1 o in q2 ma non in entrambe (unione disgiunta)
*/
queue xor_queue(queue q1, queue q2);