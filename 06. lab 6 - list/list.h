#include "item.h"

typedef struct node *list;

/*
specifica sintattica:
    newList() -> list
specifica semantica:
    postcondizione: l = nil
*/
list newList(void);

/*
specifica sintattica: 
    emptyList(list) -> boolean
specifica semantica:
    postcondizione: se l = nil allora b = true altrimenti b = false
*/
int emptyList(list l);

/*
specifica sintattica:
    consList(item, list) -> list
specifica semantica:
    postcondizione: l = <a1,a2,..,an> AND l' = <e,a1,a2,..,an>
*/
list consList(item val, list l);

/*
specifica sintattica:
    tailList(list) -> list
specifica semantica:
    precondizione: l = <a1,a2,..,an> n>0
    postcondizione: l' = <a2,..,an>
*/
list tailList(list l);

/*
specifica sintattica:
    getFirst(list) -> item
specifica semantica:
    precondizione: l = <a1,a2,..,an> n>0
    postcondizione: e = a1
*/
item getFirst (list l);

/*
specifica sintattica:
    sizeList(list) -> integer
specifica semantica:
    postcondizione: l = <a1,a2,..,an> and n>=0
*/
int sizeList (list l);

/*
specifica sintattica:
    posItem(list, item) -> integer
specifica semantica:
    postcondizione: se e è contenuto in l allora p è la posizione della prima occorrenza di e in l, altrimenti p = -1
*/
int posItem (list l, item val);

/*
specifica sintattica:
    getItem(list, integer) -> item
specifica semantica:
    precondizione: p>=0 AND sizeList(l)>p (assumiamo 0 come prima posizione)
    postcondizione: e è l'elemento che occupa in l la posizione p
*/
item getItem (list l, int pos);

/*
specifica sintattica:
    reverseList(list) -> list
specifica semantica:
    postcondizione: l = <a1,a2,..,an> AND l' = <an,..,a2,a1>
*/
list reverseList (list l);

/*
specifica sintattica:
    outputList(list)
specifica semantica:
    postcondizione: visualizza in output gli elementi di una lista l
*/
void outputList (list l);

/*
specifica sintattica:
    insertList(list, integer, item) -> list
specifica semantica:
    precondizione: p>=0 AND sizeList(l)>p (assumiamo 0 come prima posizione)
    postcondizione: l' si ottiene da l inserendo e in posizione p
*/
list insertList(list l, int pos, item val);

/*
specifica sintattica:
    removeList(list, integer) -> list
specifica semantica:
    precondizione: p>=0 AND sizeList(l)>p
    postcondizione: l' si ottiene da l eliminando l'elemento in posizione p
*/
list removeList(list l, int pos);