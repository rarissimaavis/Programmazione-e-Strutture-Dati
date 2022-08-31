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

/*
1.
specifica sintattica: cancFinoItem(list, item) -> list
    dati di input: list l, item el
    dati di output: list l'
specifica semantica:
    postcondizione: se el non è presente in l restituisce la lista senza modifiche, altrimenti in l
    non sono più presenti gli elementi di posizioni precedenti ad el
*/
list cancFinoItem(list l, item el);

/*
1.
specifica sintattica: fondiDaItem(list, list, item) -> list
    dati di input: list l1, list l2, item el
    dati di output: list new
specifica semantica:
    postcondizione: new contiene gli elementi comuni a l1 ed l2 a partire da el
*/
list fondiDaItem(list l1, list l2, item el);