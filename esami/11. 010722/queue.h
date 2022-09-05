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
specifica sintattica: canc(queue, queue) -> queue
    dati di input: queue q1, queue q2
    dati di output: queue q1
specifica semantica:
    postcondizione: da q1 vengono elininati gli elementi che non sono presenti in q2
*/
queue canc(queue q1, queue q2);