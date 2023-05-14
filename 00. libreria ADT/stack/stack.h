#include "item.h"

typedef struct c_stack *stack;

/*
specifica sintattica:
    newStack() -> stack
specifica semantica:
    postcondizione: s = nil
*/
stack newStack(void);

/*
specifica sintattica:
    emptyStack(stack) -> boolean
specifica semantica:
    postcondizione: se s = nil allora b = true altrimenti b = false
*/
int emptyStack(stack s);

/*
specifica sintattica:
    push(item, stack) -> stack
specifica semantica:
    postcondizione: s = <a1,a2,..,an> AND s' = <e,a1,a2,..,an>
*/
int push(item val, stack s);

/*
specifica sintattica:
    pop(stack) -> stack
specifica semantica:
    precondizione: s = <a1,a2,..,an> n>0
    postcondizione: s' = <a2,..,an>
*/
int pop(stack s);

/*
specifica sintattica:
    top(stack) -> item
specifica semantica:
    precondizione: s = <a1,a2,..,an> n>0
    postcondizione: e = a1
*/
item top(stack s);