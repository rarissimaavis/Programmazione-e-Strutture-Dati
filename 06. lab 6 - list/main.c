#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

/*
1. cercare l'elemento 55 nella lista 

specifica
    dati di input: lista l, item el
    dati di output: intero 1 o -1
    postcondizione: se l contiene el restituisce 1, altrimenti -1

progettazione
    1. scorri tutti gli elementi della lista
    2. se il primo elemento della lista è uguale all'elemento cercato, restituisci 1
    3. se no, continua la ricerca nel resto della lista
    4. finiti gli elementi della lista, restituisci -1
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
    return -1;
}

/*
2. cercare la posizione dell'elemento 25

specifica
    dati di input: lista l, item el
    dati di output: intero indice della posizione o -1
    postcondizione: se l contiene el restituisce la sua posizione i, altrimenti -1

progettazione
    1. scorri tutti gli elementi della lista
    2. se il primo elemento della lista è uguale all'elemento cercato, restituisci la sua posizione 
    3. se no, continua la ricerca nel resto della lista
    4. finiti gli elementi della lista, restituisci -1
*/

int cerca_posizione(list l, item el)
{
    for (int i = 0; !emptyList(l); i++)
    {
        if (eq(el, getFirst(l)))
        {
            return i;
        }
        l = tailList(l);
    }
    return -1;
}

/*
3. rimuovere dalla lista l'elemento in posizione centrale senza avere la conoscenza a priori della dimensione della lista

specifica
    dati di input: lista l
    dati di output: lista l'
    postcondizione: l' si ottiene da l eliminando l'elimento centrale

progettazione
    1. rimuovi dalla lista l'elemento la cui posizione è (dimensione della lista-1)/2
*/
list rimuovi_centrale(list l)
{
    return removeList(l, (sizeList(l)-1)/2);
}

int main ()
{
    list l = newList();
    int n, el;
    printf("quanti interi vuoi inserire nella lista? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        input_item(&el);
        l = consList(el, l);
    }
    outputList(l);

    printf("\n55 è nella lista? %d\n", cerca_elemento(l, 55));

    printf("\nin che posizione si trova 25? %d\n\n", cerca_posizione(l, 25));
    
    rimuovi_centrale(l);
    printf("elemento centrale rimosso:\n");
    outputList(l);
    return 0;
}
