#include "item.h"

typedef struct node *list;

list newList(void);
int emptyList(list l);
list consList(key val, list l);
list tailList(list l);
key getFirst (list l);
int sizeList (list l);
int poskey (list l, key val);
key getkey (list l, int pos);
list reverseList (list l);
void outputList (list l);
list insertList(list l, int pos, key val);
list removeList(list l, int pos);