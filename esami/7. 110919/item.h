typedef int item;

#define NULLITEM 0

int eq(item x, item y); //controlla se due item sono uguali
void input_item(item *x); //inserisce un item 
void output_item(item x); //mostra in output l'item x
int minore(item a, item b); //verifica se a<b
int maggiore(item a, item b); //verifica se a>b