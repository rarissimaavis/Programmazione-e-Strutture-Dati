#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node
{
     key value;
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

list consList(key val, list l)
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


key getFirst (list l)
{
     key e;
     if (l != NULL)
     {
          e = l->value;
     }
     else
     {
          e = NULLkey;
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

int poskey (list l, key val)
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

key getkey (list l, int pos)
{
     key e;
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
          e = NULLkey;
     }
     return e;
}

list reverseList (list l)
{
     list rev;
     key val;
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
     key val;
     while (!emptyList(l))
     {
          val = getFirst(l);
          printf("elemento di posizione %d: ", i);
          output_key(val);
          printf("\n");
          l = tailList(l);
          i++;
     }
}

list insertList(list l, int pos, key val)
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
     
