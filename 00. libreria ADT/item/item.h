#ifndef ITEM_H
#define ITEM_H
typedef int item;
#endif

#define NULLITEM 0

int eq(item x, item y); //controlla se due item sono uguali
void input_item(item *x); //inserisce un item 
void output_item(item x); //mostra in output l'item x
