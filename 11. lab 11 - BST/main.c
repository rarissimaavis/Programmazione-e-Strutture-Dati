#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "queue.h"
#include "item.h"

/*
2. nodi in un Intervallo
   Dato un albero binario di ricerca T i cui valori sono interi e due valori interi A e B (tale che A<B), 
   stampare in maniera ordinata tutti i nodi di T che sono compresi nell’intervallo [A, B] (estremi inclusi).

specifica
    dati di input: BST T, int A e B
    precondizione: l'albero deve esistere
    postcondizione: la funzione stampa in ordine i valori compresi tra A e B

progettazione
    1. se x (radice) è > A continua nel sottoalbero sinistro
    2. se x è compreso tra A e B inizia la stampa 
    3. se x è <>> B continua nel sottoalbero destro
*/

void output_intervallo(BST T, int A, int B)
{
    if (emptyBST(T))
    {
        return;
    }
    int x = getItem(getRoot(T));
    if (A < x)
    {
        output_intervallo(figlioSX(T), A, B);
    }
    if (A <= x && x <= B)
    {
        output_item(x);
        printf(" ");
    }
    if (x < B)
    {
        output_intervallo(figlioDX(T), A, B);
    }
} 

/*
3. bilanciato
   Dato un array di interi in input, costruire un albero binario di ricerca perfettamente bilanciato 
   i cui nodi siano popolati dagli elementi dell’array.
   NOTA. l’array in input che caratteristiche dovrebbe avere?

specifica
    dati di input: array a di interi, int numel
    dati di output: BST T
    precondizione: numel è una potenza di 2 meno 1
    postcondizione: T contiene gli elementi dell'array a

progettazione
    1. scorri gli elementi dell'array e inseriscili in T
    2. restituisci T
*/

BST input_BST(int *a, int numel)
{
    BST T = newBST();
    for (int i = 0; i < numel; i++)
    {
        T = insert(T, a[i]);
    }
    return T;
}

/*
4. nodi ad altezza k
   Dato un albero binario di ricerca T i cui item sono interi e un intero k, scrivere una funzione che 
   restituisca tutti i nodi di T che hanno altezza k. L’output è una struttura dati a propria scelta.

specifica
    dati di input: BST T, queue q, interi k e liv
    dati di output: queue q'
    precondizione: l'albero e la coda devono esistere
    postcondizione: q' contiene i nodi di T ad altezza k

progettazione
    1. passo base: se arrivi al livello k inserisci il valore nella coda e restituisci la nuova coda
    2. passo ricorsivo: se non sei ancora all'altezza k continua sul sottoalbero sx e dx al livello successivo
*/

queue altezzak(BST T, queue q, int k, int liv)
{
    if (emptyBST(T))
    {
        return NULL;
    }
    if (k == liv)
    {
        enqueue(getItem(getRoot(T)), q);
        return q;
    }
    else if (k > liv)
    {
        altezzak(figlioSX(T), q, k, liv+1);
        altezzak(figlioDX(T), q, k, liv+1);
    }
}

/*
5. mediano
   dato un albero binario di ricerca T i cui item sono numeri interi e un valore intero U, 
   stabilire se il nodo che ha valore U in T è il mediano del sottoalbero di cui esso è radice.
   (verificare se il numero di nodi a sx di U è uguale al numero di nodi a dx di U)

specifica
    dati di input: BST T, i
    dati di output: boolean
    precondizione: l'albero deve esistere
    postcondizione: se U è mediano del sottoalbero di cui è radice allora v = 1, altrimenti v = 0

progettazione
    1. se U è contenuto in T,
        1.1 se U è uguale alla radice, vedi se il figlio sx e dx hanno lo stesso numero di nodi
            e restitituisci il valore di verità corrispondente (funzione conta_nodi)
        1.2 se U è < della radice, continua nel sottoalbero sinistro
        1.3 se U è > della radice, continua nel sottoalbero destro

raffinamento: funzione conta_nodi
progettazione
    1. passo base: se T è vuoto restituisci 0
    2. passo ricorsivo: restituisci 1 + il risultato della chiamata di funzione sul figlio sx e dx
*/

int conta_nodi(BST T)
{
    if (emptyBST(T))
    {
        return 0;
    }
    return 1 + conta_nodi(figlioSX(T)) + conta_nodi(figlioDX(T));
}

int mediano(BST T, item U)
{
    if (contains(T, U))
    {
        int root = getItem(getRoot(T));
        if (root == U)
        {
            return conta_nodi(figlioSX(T)) == conta_nodi(figlioDX(T));
        }
        else if (U < root)
        {
            mediano(figlioSX(T), U);
        }
        else if (root < U)
        {
            mediano(figlioDX(T), U);
        }
    }
}

int main(void)
{
    int a[7] = {10,6,18,4,8,15,21}; //numel = 2^k-1
    
    BST TB;
    TB = newBST();
    TB = input_BST(a, 7);
    output_BST(TB, 0);
    
    printf("\ni nodi compresi tra 5 e 16 sono: ");
    output_intervallo(TB, 5, 16);
    
    queue nodik = newQueue();
    altezzak(TB, nodik, 2, 0);
    printf("\nnodi ad altezza k = 2: ");
    output_queue(nodik);
    
    int med;
    med = mediano(TB, 18);
    printf("\n18 è mediano? %i\n", med);
    return 0;
}