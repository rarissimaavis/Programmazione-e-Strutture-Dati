#include "item.h"

typedef struct c_queue *queue;

/*
specifica sintattica:
    newQueue() -> queue
specifica semantica:
    postcondizione: q = nil
*/
queue newQueue(void);

/*
specifica sintattica:
    emptyQueue(queue) -> boolean
specifica semantica:
    postcondizione: se q = nil allora b = true altrimenti b = false
*/
int emptyQueue(queue q);

/*
specifica sintattica:
    enqueue(item, queue) -> queue
specifica semantica:
    postcondizione: se q = nil allora q' = <e>, se q = <a1,a2,..,an> con n>0 allora q' = <a1,a2,..an,e>
*/
int enqueue(item val, queue q);

/*
specifica sintattica:
    dequeue(queue) -> item
specifica semantica:
    precondizione: <a1,a2,..,an> n>0 (q != nil)
    postcondizione: a = a1 e l'elemento a1 viene rimosso da q
*/
item dequeue(queue q);

void output_queue(queue q);