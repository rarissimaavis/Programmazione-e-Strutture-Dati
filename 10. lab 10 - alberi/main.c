#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Btree.h"
#include "item.h"

/*
1. creazione da file
   con la funzione inputBTree, realizzare un albero binario i cui nodi contengono dei numeri interi letti da file.

specifica
    dati di input: char *fname, int *sizea
    dati di output: Btree T
    postcondizione: T ha come elementi gli interi letti dal file

progettazione
    1. apri il file dato in input in lettura e conta quanti interi ha, chiudi il file
    2. alloca lo spazio necessario per l'array a
    3. apri il file in lettura e inserisci gli interi nell'array a, chiudi il file
    4. aggiorna il valore di sizea con il numero di elementi contenuti nel file
    5. crea l'albero T a partire dall'array a (funzione input_Btree)

raffinamento: funzione input_Btree
progettazione
    1. passo base: se i è >= del numero di elemnti restituisci NULL
    2. passo ricorsivo: restituisci l'albero creato con l'elemento di indice i nell'array a
       e gli alberi che si creano richiamando la funzione con indici 2i+1 e 2i+2
*/

Btree input_Btree(int *a, int i, int numel)
{
    if (i >= numel)
    {
        return NULL;
    }
    return consBtree(a[i], input_Btree(a, 2*i+1, numel), input_Btree(a, 2*i+2, numel));
}

Btree file_input_Btree(char *fname, int *sizea)
{
    int i, quanti = 0;
    int *a;
    FILE *fp = fopen(fname,"r");
    if (fp == NULL)
    {
        exit(-1);
    }
    while (fscanf(fp, "%d\n", &i) == 1)
    {
        quanti++;
    }
    fclose(fp);
    a = malloc(quanti*sizeof(int));
    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        exit(-1);
    }
    for (i = 0; i < quanti; i++)
    {
        fscanf(fp, "%d\n", &a[i]);
    }
    fclose(fp);
    *sizea = quanti;
    Btree T = input_Btree(a, 0, *sizea);
    return T;
}

/*
2. conta foglie
   un nodo foglia è un nodo che non ha ulteriori ramificazioni. 
   Realizzare una funzione che conti il numero di foglie presenti nell’albero.

specifica
    dati di input: Btree T
    dati di output: int (numero foglie)
    precondizione: l'albero deve esistere
    postcondizione: il numero restituito corrisponde al numero di foglie presenti nell'albero

progettazione
    1. passo base: se l'albero è vuoto restituisci 0
    2. passo base: se i sottoalberi sinistro e destro sono vuoti restituisci 1
    3. passo ricorsivo: restituisci la somma di conta_foglie sul figlio sinistro e sul figlio destro
*/

int conta_foglie(Btree T)
{
    if (emptyBtree(T))
    {
        return 0;
    }
    else if (emptyBtree(figlioSX(T)) && emptyBtree(figlioDX(T)))
    {
        return 1;
    }
    else
    {
        return conta_foglie(figlioDX(T)) + conta_foglie(figlioSX(T));
    }
}

/*
3. albero speculare
   l’albero speculare è quello ottenuto invertendo ciascun nodo sinistro con il nodo destro. 
   Realizzare una funzione che dato un albero binario crei l’albero speculare BTree speculare(BTree albero)

specifica
    dati di input: Btree T
    dati di output: Btree T'
    precondizione: l'albero deve esistere
    postcondizione: T' è lo speculare di T

progettazione
    1. passo base: se l'albero è vuoto restituisci NULL
    2. passo ricorsivo: restituisci l'albero che ha come radice la stessa radice di T, 
       e per figli sx e dx gli speculari dei figlii sx e dx di T
*/

Btree speculare(Btree T)
{
    if (emptyBtree(T))
    {
        return NULL;
    }
    return consBtree(getItem(getRoot(T)), speculare(figlioDX(T)), speculare(figlioSX(T)));
}

/*
4. min/max
   scrivere due funzioni di ricerca del nodo con valore minimo e massimo, rispettivamente, 
   e restituire tale valore in output. Si è liberi di scegliere la visita dell’albero che si preferisce, 
   dopotutto vanno visitati tutti i nodi dell’albero binario per poter individuare il nodo con valore minimo e massimo.

(faccio solo min tanto sono uguali)
specifica
    dati di input: Btree T
    dati di output: int min
    precondizione: l'albero deve esistere
    postcondizione: min è il nodo con valore minimo

progettazione
    1. se l'albero è vuoto restituisci il massimo valore intero
    2. assegna a min il valore della radice, a minSX il valore del minimo del sottoalbero sinistro
       e a minDX il valore del minimo del sottoalbero destro
    3. se il min è minore dei minimi dei sottoalberi sx e dx restituisci min
    4. se il minimo del sottoalbero sx è minore di quello del sottoalbero dx restituisci minSX
    5. se il minimo del sottoalbero dx è minore di quello del sottoalbero sx restituisci minDX
*/

int min_Btree(Btree T)
{
    int min, minSX, minDX;
    if (emptyBtree(T))
    {
        return 2147483647;
    }
    min = getItem(getRoot(T));
    minSX = min_Btree(figlioSX(T));
    minDX = min_Btree(figlioDX(T));
    if (min < minSX && min < minDX)
    {
        return min;
    }
    else if (minSX < minDX)
    {
        return minSX;
    }
    else if (minDX < minSX)
    {
        return minDX;
    }
}

int max_Btree(Btree T)
{
    int max, maxSX, maxDX;
    if (emptyBtree(T))
    {
        return -2147483648;
    }
    max = getItem(getRoot(T));
    maxSX = max_Btree(figlioSX(T));
    maxDX = max_Btree(figlioDX(T));
    if (max > maxSX && max > maxDX)
    {
        return max;
    }
    else if (maxSX > maxDX)
    {
        return maxSX;
    }
    else if (maxDX > maxSX)
    {
        return maxDX;
    }
}

/*
5. uguaglianza tra alberi
   due alberi sono uguali se contengono lo stesso numero di nodi disposti nella stessa maniera e con gli stessi valori. 
   Implementare una funzione char uguali(BTree albero1, BTree albero2) che dati in input due alberi dica se sono uguali.

specifica
    dati di input: Btree T1, T2
    dati di output: boolean
    precondizione: gli alberi devono esistere
    postcondzione: se gli alberi sono uguali v = 1, altrimenti v = 0

progettazione
    1. passo base: se T1 e T2 sono vuoti restituisci 1
    2. passo base: le radici di T1 e T2 sono diverse restituisci 0
    3. passo ricorsivo: se i figli sinistri e i figli destri sono uguali restituisci 1
*/

int uguaglianza(Btree T1, Btree T2)
{
    if (emptyBtree(T1) && emptyBtree(T2))
    {
        return 1;
    }
    if (getItem(getRoot(T1)) != getItem(getRoot(T2)))
    {
        return 0;
    }
    else if (uguaglianza(figlioSX(T1), figlioSX(T2)) && uguaglianza(figlioDX(T1), figlioDX(T2)))
    {
        return 1;
    }
}

int main(void)
{
    int numel, foglie, min, max, eq, numel2;

    Btree T;
    T = newBtree();
    T = file_input_Btree("input.txt", &numel);
    printf("albero 1: \n");
    output_Btree(T, 0);
    
    Btree T2;
    T2 = newBtree();
    T2 = file_input_Btree("input2.txt", &numel2);
    printf("\nalbero 2: \n");
    output_Btree(T2, 0);
    
    foglie = conta_foglie(T);
    printf("\nn foglie: %d\n", foglie);
    
    T = speculare(T);
    printf("\nalbero speculare: \n");
    output_Btree(T, 0);
    
    min = min_Btree(T);
    max = max_Btree(T);
    printf("\nmin: %d\n", min);
    printf("max: %d\n", max);
    
    eq = uguaglianza(T, T2);
    printf("\n1 e 2 sono uguali? %d\n", eq);
    
    return 0;
}