#include "item.h"

typedef struct c_stack *stack;

stack newStack(void);
int emptyStack(stack s);
int push(item val, stack s);
int pop(stack s);
item top(stack s);

stack input_stack(stack s);
void output_stack(stack s);

/*
specifica sintattica: al_centro(stack, stack) -> stack
    dati di input: stack s1, stack s2
    dati di output: stack s1'
specifica semantica: 
    precondizione: s2 deve rimanere invariato
    postcondizione: s1' contiene gli elementi di s2 al centro di s1
*/
stack al_centro(stack s1, stack s2);