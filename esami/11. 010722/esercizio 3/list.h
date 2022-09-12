#include "item.h"

typedef struct node *list;

list newList(void);
int emptyList(list l);
list input_list(list l);
list consList(item val, list l);
list tailList(list l);
item getFirst (list l);
int sizeList (list l);
int posItem (list l, item val);
item getItem (list l, int pos);
list reverseList (list l);
void outputList (list l);
list insertList(list l, int pos, item val);
list removeList(list l, int pos);

//int sizeList_ric(list l);
//item centrale_ric(list l);

item get_mid(list l, int i);
