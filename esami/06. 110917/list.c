//esame 110917
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node
{
    item value;
    struct node *next;
};

list newList(void)
{
    return NULL;
}

int emptyList(list l)
{
    return l == NULL;
}

list input_list(list l)
{
    int n, el;
    printf("quanti interi vuoi inserire nella lista? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        input_item(&el);
        l = consList(el, l);
    }
    return l;
}

list consList(item val, list l)
{
     struct node *nuovo;
     nuovo = malloc(sizeof(struct node));
     if (nuovo != NULL)
     {
          nuovo->value = val;
          nuovo->next = l;
          l = nuovo;
     }
     return l;
}

list tailList(list l)
{
     list temp;
     if (l != NULL)
     {
          temp = l->next;
     }
     else
     {
          temp = NULL;
     }
     return temp;
}


item getFirst (list l)
{
     item e;
     if (l != NULL)
     {
          e = l->value;
     }
     else
     {
          e = NULLITEM;
     }
     return e;
}

int sizeList (list l)
{
     int n = 0;
     while (!emptyList(l))
     {
          n++;
          l = tailList(l);
     }
     return n;
}

int posItem (list l, item val)
{
     int pos = 0;
     int found = 0;
     while (!emptyList(l) && !found)
     {
          if (eq(getFirst(l), val))
          {
               found = 1;
          }
          else
          {
               pos++;
               l = tailList(l);
          }
     }
     if (!found)
     {
          pos = -1;
     }
     return pos;
}

item getItem (list l, int pos)
{
    item e;
    int i = 0;
    while (i < pos && !emptyList(l))
    {
        i++;
        l = tailList(l);
    }
    if (!emptyList(l))
    {
        e = getFirst(l);
    }
    else
    {
        e = NULLITEM;
    }
    return e;
}

list reverseList (list l)
{
    list rev;
    item val;
    rev = newList();
    while (!emptyList(l))
    {
        val = getFirst(l);
        rev = consList(val, rev);
        l = tailList(l);
    }
    return rev;
}

void outputList (list l)
{
    int i = 0;
    item val;
    while (!emptyList(l))
    {
        val = getFirst(l);
        printf("elemento di posizione %d: ", i);
        output_item(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
}

list insertList(list l, int pos, item val)
{
    list l1, prec = l;
    if (pos == 0)
    {
        return consList(val, l);
    }
    for (int i = 0; i < pos-1 && prec != NULL; i++)
    {
        prec = prec->next;
    }
    if (prec == NULL)
    {
        return l;
    }
    l1 = consList(val, prec->next);
    prec->next = l1;
    return l;
}

list removeList(list l, int pos)
{
    list l1, prec = l;
    if (pos == 0 && l != NULL)
    {
        l1 = l;
        l = tailList(l);
        free(l1);
    }
    else
    {
        for (int i = 0; i < pos-1 && prec != NULL; i++)
        {
            prec = prec->next;
        }
        if (prec != NULL && prec->next != NULL)
        {
            l1 = prec->next;
            prec->next = l1->next;
            free(l1);
        }
    }
    return l;
}
     
/*
1. cancFinoITem

progettazione
    1. finchè la lista non è vuota e il primo elemento è diverso da el, continua nel resto della lista
    2. restituisci l
*/

list cancFinoItem(list l, item el)
{
    while (!emptyList(l) && !eq(getFirst(l), el))
    {
        l = tailList(l);
    }
    return l;
}

/*
2. fondiDaItem

progettazione 
    1. aggiorna l1 ed l2 solo con gli elementi successivi ad el (funzione cancFinoItem)
    2. scorri gli elementi di l1, 
        2.1 se il primo elemento della lista p è presente in l2 e non in new, inseriscilo in new
        2.2 continua nel resto della lista
    3. restituisci new

raffinamento: funzione cerca_elemento
progettazione
    1. scorri tutti gli elementi della lista
    2. se il primo elemento della lista è uguale all'elemento cercato, restituisci 1
    3. se no, continua la ricerca nel resto della lista
    4. finiti gli elementi della lista, restituisci 0
*/

int cerca_elemento(list l, item el)
{
    for (int i = 0; !emptyList(l); i++)
    {
        if (eq(el, getFirst(l)))
        {
            return 1;
        }
        l = tailList(l);
    }
    return 0;
}

list fondiDaItem(list l1, list l2, item el)
{
    list new = newList();
    l1 = cancFinoItem(l1, el);
    l2 = cancFinoItem(l2, el); 
    for (int i = 0; !emptyList(l1); i++)
    {
        item p = getFirst(l1);
        if (cerca_elemento(l2, p) && !cerca_elemento(new, p))
        {
            new = consList(p, new);
        }
        l1 = tailList(l1);
    }
    return new;
}