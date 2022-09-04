#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "PQueue.h"

/*
1. min/max
   dato un albero heap di nodi i cui item sono interi, realizzare due funzioni che restituiscano 
   il valore del nodo massimo e del nodo minimo presenti nell’albero.

specifica
    dati di input: PQueue pq
    dati di output: key max/min
    postcondizione: max/min è il valore del massimo/minimo

progettazione: max
    1. restituisci l'elem con la massima priorità (funzione getMax)

progettazione: min
    1. crea la pqueue tmp
    2. assegna a curr il valore massimo di pq
    3. finchè pq non è vuota,
        3.1 inserisci curr in tmp
        3.2 elimina il massimo da pq
        3.3 aggiorna il valore di curr con il massimo attuale
    4. finchè tmp non è vuota, inserisci in pq il massimo di tmp ed eliminalo 
    5. libera lo spazio occupato da tmp
    6. restituisci curr (ultimo massimo, cioè il minimo)
*/

key max_PQ(PQueue pq)
{
    return getMax(pq);
}

key min_PQ(PQueue pq)
{
    PQueue tmp = newPQ();
    key curr = getMax(pq), min;
    while (!emptyPQ(pq))
    {
        insert(tmp, curr);
        deleteMax(pq);
        curr = getMax(pq);
    }
    while (!emptyPQ(tmp))
    {
        insert(pq, getMax(tmp));
        deleteMax(tmp);
    }
    free(tmp);
    return curr;
}

/*
2. incrementa chiave
   dato un albero heap H i cui nodi sono item interi, un valore K e un valore newK (tale che K<newK), scrivere 
   una funzione che modifichi l’albero H cercando il nodo il cui valore corrisponde a K e rimpiazzandolo con newK.
   Nota. il nodo incrementato potrebbe non trovarsi più in una posizione che rispetta la condizione 
   dell’albero di essere uno heap

specifica
    dati di input: PQueue pq, key k, key new_k
    precondizione: k < new_k
    postcondizione: il nodo che ha valore k viene modificato con new_k

progettazione
    1. crea la pqueue tmp
    2. finchè pq non è vuota, inserisci in tmp il massimo di pq ed eliminalo
    3. finchè tmp non è vuota,
        3.1 assegna a curr il massimo di tmp
        3.2 se curr è uguale a k, inserisci in pq il valore new_k
        3.3 altrimenti inserisci curr
        3.4 elimina il massimo da tmp
    4. libera lo spazio occupato da tmp
*/

void incrementa_chiave(PQueue pq, key k, key new_k)
{
    PQueue tmp = newPQ();
    key curr;
    while (!emptyPQ(pq))
    {
        insert(tmp, getMax(pq));
        deleteMax(pq);
    }
    while (!emptyPQ(tmp))
    {
        curr = getMax(tmp);
        if (curr == k)
        {
            insert(pq, new_k);
        }
        else
        {
            insert(pq, curr);
        }
        deleteMax(tmp);
    }
    free(tmp);
}

/*
3. heapify array
   dato un array di interi non ordinato, realizzare una funzione heapify(int a[]) tale da restituire 
   un array i cui elementi sono disposti in maniera tale da corrispondere ad uno heap

specifica
    dati di input: array du int a, int numel, int i
    postcondizione: l'ordine degli elementi di a' è tale da corrispondere ad uno heap

progettazione
    1. inizializza max a i, sx a 2i+1, dx a 2i+2
    2. se l'elemento all'indice sx (figlio sx) è maggiore di quello di max, aggiorna il valore di max con sx
    3. se l'elemento all'indice dx (figlio dx) è maggiore di quello di max, aggiorna il valore di max con dx
    4. se max è diverso da i, scambia gli elmenti di indice max e i
    5. passo ricorsivo: continua con il nuovo indice max
*/

void heapify(int *a, int numel, int i)
{
    int max = i, sx = 2*i+1, dx = 2*i+2, tmp;
    if (sx < numel && a[sx] > a[max])
    {
        max = sx;
    }
    if (dx < numel && a[dx] > a[max])
    {
        max = dx;
    }
    if (max != i)
    {
        tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
        heapify(a, numel, max);
    }
}

void crea_heap(int a[], int numel)
{
    int ultimo_genitore = (numel-1)/2;
    for (int i = ultimo_genitore; i >= 0; i--)
    {
        heapify(a, numel, i);
    }
}

/*
4. stack con coda a priorità
   attraverso il tipo ADT Coda a Priorità, simulare una struttura dati di tipo stack che memorizza valori interi. 
   La coda a priorità dovrà simulare opportunamente le funzioni per l’inserimento e l’estrazione di elementi 
   nello stack (push e pop)
*/

int push(PQueue pq, key k)
{
    if (k < getMax(pq))
    {
        return 0;
    }
    insert(pq, k);
    return 1;
}

int pop(PQueue pq)
{
    return deleteMax(pq);
}

/*
5. merge di code
   date due code a priorità Q1 e Q2, scrivere una funzione che crei una terza coda Q3 ottenuta per combinazione 
   delle due code date in input PQueue merge(PQueue q1, PQueue q2)
   Le code originali non devono essere distrutte

specifica
    dati di input: PQueue pq1, PQueue pq2
    dati di output: PQueue pq3
    postcondizione: pq3 è la combinazione di pq1 e pq2, pq1 e pq2 continuano ad esistere

progettazione
    1. inserisci gli elementi di pq1 in pq3 e in tmp
    2. inserisci di nuovo gli elementi di tmp in pq1
    3. inserisci gli elementi di pq2 in pq3 e in tmp
    4. inserisci di nuovo gli elementi di tmp in pq2
    5. libera lo spazio occupato da tmp
    6. restituisci pq3
*/

PQueue merge(PQueue pq1, PQueue pq2)
{
    PQueue pq3 = newPQ(), tmp = newPQ();
    while (!emptyPQ(pq1))
    {
        insert(pq3, getMax(pq1));
        insert(tmp, getMax(pq1));
        deleteMax(pq1);
    }
    while (!emptyPQ(tmp))
    {
        insert(pq1, getMax(tmp));
        deleteMax(tmp);
    }
    while (!emptyPQ(pq2))
    {
        insert(pq3, getMax(pq2));
        insert(tmp, getMax(pq2));
        deleteMax(pq2);
    }
    while (!emptyPQ(tmp))
    {
        insert(pq2, getMax(tmp));
        deleteMax(tmp);
    }
    free(tmp);
    return pq3;
}

int main(void)
{
    int a[9] = {100,19,36,17,3,25,1,2,7};
    crea_heap(a, 9);
    printf("heapificato: ");
    for (int i = 0; i < 9; i++) printf("%d ", a[i]);

    PQueue pq = input_PQ(a, 9);
    printf("\npq: ");
    output_PQ(pq);

    printf("\nmax: ");
    output_key(max_PQ(pq));
    printf("\nmin: ");
    output_key(min_PQ(pq));

    incrementa_chiave(pq, 19, 43);
    printf("\n\nincrementa chiave: ");
    output_PQ(pq);

    push(pq, 111);
    printf("\npush: ");
    output_PQ(pq);
    pop(pq);
    printf("\npop: ");
    output_PQ(pq);

    int b[7] = {4,5,8,9,11,23,35};
    crea_heap(b, 7);

    PQueue pq2 = input_PQ(b, 7);
    printf("\npq2: ");
    output_PQ(pq2);

    PQueue q3 = merge(pq, pq2);
    printf("\nmerge: ");
    output_PQ(q3);
}
