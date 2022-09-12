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

//grazie Anto tvb <3
item get_mid(list l, int i)
{
    if (emptyList(l))
    {
        return NULLITEM;
    }
    if (getItem(l, i) == NULLITEM)
    {
        return getFirst(l);
    }
    else
    {
        return get_mid(tailList(l), i+1);
    }
}

/*
int sizeList_ric(list l)
{
    if (emptyList(l))
    {
        return 0;
    }
    return 1 + sizeList_ric(tailList(l));
}

item centrale_ric(list l)
{
    if (sizeList_ric(l) <= 2)
    {
        return getFirst(l);
    }
    l = removeList(l, 0);
    l = removeList(l, sizeList_ric(l)-1);
    return centrale_ric(l);
}
*/