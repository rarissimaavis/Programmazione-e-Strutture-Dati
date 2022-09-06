//esame 150722
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "stack.h"

struct node
{
    item value;
    struct node *next;
};

struct c_stack
{
    struct node *top;
    int numel;
};

stack newStack(void)
{
    stack s;
    s = malloc(sizeof(struct c_stack));
    if (s == NULL)
    {
        return NULL;
    }
    s->numel = 0;
    s->top = NULL;
    return s;
}

int emptyStack(stack s)
{
    return s->numel == 0;
}

int push(item val, stack s)
{
    struct node *nuovo;
    nuovo = malloc(sizeof(struct node));
    if (nuovo == NULL)
    {
        return 0;
    }
    nuovo->value = val;
    nuovo->next = s->top;
    s->top = nuovo;
    (s->numel)++;
    return 1;
}

int pop(stack s)
{
    if (s->numel == 0)
    {
        return 0;
    }
    struct node *temp;
    temp = s->top;
    s->top = s->top->next;
    free(temp);
    (s->numel)--;
    return 1;
}

item top(stack s)
{
    item e;
    if (s->numel > 0)
    {
        e = s->top->value;
    }
    else
    {
        e = NULLITEM;
    }
    return e;
}

stack input_stack(stack s)
{
    int x;
    input_item(&x);
    while (x != -1)
    {
        push(x, s);
        input_item(&x);
    }
    return s;
}

void output_stack(stack s)
{
    while (!emptyStack(s))
    {
        output_item(top(s));
        printf(" ");
        pop(s);
    }
    printf("\n");
}

/*
2. stack al centro

progettazione
    1. inserisci i primi size/2 elementi di s1 in tmp
    2. inserisci gli elementi di s2 in tmp
    3. inserisci gli elementi che prima erano in s2 in s1 e di nuovo in s2
    4. inserisci gli elementi di tmp in s1
    5. libera lo spazio allocato da tmp
    6. restituisci s1
*/

stack al_centro(stack s1, stack s2)
{
    stack tmp = newStack();
    int size_s1 = s1->numel, size_s2 = s2->numel;
    for (int i = 0; i < size_s1/2; i++)
    {
        push(top(s1), tmp);
        pop(s1);
    }
    while (!emptyStack(s2))
    {
        push(top(s2), tmp);
        pop(s2);
    }
    for (int i = 0; i < size_s2; i++)
    {
        push(top(tmp), s1);
        push(top(tmp), s2);
        pop(tmp);
    }
    while (!emptyStack(tmp))
    {
        push(top(tmp), s1);
        pop(tmp);
    }
    free(tmp);
    return s1;
}

        
