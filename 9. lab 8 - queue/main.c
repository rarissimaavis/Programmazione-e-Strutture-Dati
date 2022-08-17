#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

/*
1. coda di punti
   creare una coda i cui item sono ADT punto. 
   Le coordinate sono inserite da tastiera ma non è noto a priori il numero di punti da inserire. 
   Prevedere un opportuno input che interrompa l’inserimento dei dati da parte dell’utente.

specifica
    dati di input: queue q
    dati di output: queue q'
    precondizione: q deve esistere
    postcondizione: q' contiene i punti inseriti da tastiera

progettazione
    1. inizializza check a 1
    2. finchè check = 1:
       2.1 inserisci da tastiera ascissa e ordinata di un punto
       2.2 crea il punto
       2.3 inserisci il punto nella coda
       2.4 chiedi se inserire un altro punto e aggiorna il valore di check
    3. restituisci q
*/

queue input_coda_punti(queue q)
{
    float x, y;
    int check = 1;
    item p;
    while (check == 1)
    {
        printf("ascissa: ");
		scanf("%f", &x);
		printf("ordinata: ");
		scanf("%f", &y);
        p = creapunto(x, y);
        enqueue(p, q);
        printf("inserire un altro punto? (1 si/0 no) ");
        scanf("%d", &check);
    }
    printf("\n");
    return q;
}

queue copia_queue(queue q)
{
    item p;
    queue copia, tmp;
    copia = newQueue();
    tmp = newQueue();
    while (!emptyQueue(q))
    {
        p = dequeue(q);
        enqueue(p, copia);
        enqueue(p, tmp);
    }
    while (!emptyQueue(tmp))
    {
        p = dequeue(tmp);
        enqueue(p, q);
    }
    free(tmp);
    return copia;
}

/*
2. sottocode
   a partire dalla coda Q appena realizzata, implementare una funzione che divide la coda in quattro sottocode
   Q1, Q2, Q3 e Q4 di cui ciascuna conterrà i punti di uno dei quattro quadranti del piano cartesiano. 
   (NOTA: al termine della divisione, la coda Q non ha più ragione di esistere)

specifica 
    dati di input: queue q
    dati di output: array di 4 queue
    precondizione: q contiene almeno un elemento
    postcondizione: si creano 4 code ciascuna contenente i punti di un quadrante e q viene deallocata

progettazione
    1. crea un array di 4 queue piano_cart e alloca lo spazio necessario
    2. finchè q non è vuota,
       2.1 considera il suo primo elemento (dequeue)
       2.2 se la sua ascissa è >= 0, se l'ordinata è positiva inserisci il punto nella prima coda (primo quadrante), 
           se è negativa inseriscilo nella quarta
       2.3 se la sua ascissa è negativa, se l'ordinata è positiva inserisci il punto nella seconda coda, 
           se è negativa inseriscilo nella terza
    3. libera lo spazio occupato da q
    4. restituisci piano_cart

*/

queue *sottocode(queue q)
{
    item p;
    queue *piano_cart = malloc(4*sizeof(queue));
    piano_cart[0] = newQueue();
    piano_cart[1] = newQueue();
    piano_cart[2] = newQueue();
    piano_cart[3] = newQueue();
    while (!emptyQueue(q))
    {
        p = dequeue(q);
        if (ascissa(p) >= 0)
        {
            if (ordinata(p) >= 0)
            {
                enqueue(p, piano_cart[0]);
            }
            else
            {
                enqueue(p, piano_cart[3]);
            }
        }
        else
        {
            if (ordinata(p) >= 0)
            {
                enqueue(p, piano_cart[1]);
            }
            else
            {
                enqueue(p, piano_cart[2]);
            }
        }
    }
    free(q);
    return piano_cart;
}

/*
3. spezzata
   scelta una delle quattro sottocode realizzate al passo precedente, calcolare la lunghezza della 
   spezzata risultante dalla congiunzione dei punti presenti nella coda secondo l’ordine con il quale 
   appaiono nella coda stessa. (NOTA: la coda non deve essere distrutta.)

specifica
    dati di input: queue q
    dati di output: float len
    precondizione: la coda deve avere più di un elemento
    postcondizione: len è la somma delle distanze tra i punti della coda

progettazione
    1. inizializza len a 0
    2. crea la queue tmp
    3. prendi il primo elemento della coda (p1)
    4. finchè q non è vuota,
        4.1 prendi il primo elemento della coda (p2)
        4.2 calcola la distanza tra p1 e p2 e incrementa len
        4.3 inserisci p1 nella coda tmp
        4.4 aggiorna il valore di p1 con quello di p2
    5. inserisci l'ultimo elemento di q in tmp
    6. finchè tmp non è vuota, prendi il suo primo elemento e inseriscilo in q
    7. libera lo spazio occupato da tmp
    8. restituisci len
*/

float spezzata(queue q)
{
    float len = 0;
    item p, p1, p2;
    queue tmp;
    tmp = newQueue();
    p1 = dequeue(q);
    while (!emptyQueue(q))
    {
        p2 = dequeue(q);
        len += distanza(p1, p2);
        enqueue(p1, tmp);
        p1 = p2;
    }
    enqueue(p2, tmp);
    while (!emptyQueue(tmp))
    {
        p = dequeue(tmp);
        enqueue(p, q);
    }
    free(tmp);
    return len;
}

/*
4. concatenazione
   implementare una funzione di concatenazione tra code queue concatena (queue q1, queue q2) 
   che restituisce una nuova coda ottenuta per concatenazione delle due date code in input. 
   Con tale funzione di concatenazione, costruire una coda Q’ a partire dalle sottocode Q1, Q2, Q3 e Q4 
   assicurando che gli elementi appaiano in ordine discendente di quadrante Q’ = head-> (Q4, Q3, Q2, Q1) <-tail  
   (NOTA: Al termine della concatenazione, le sottocode non hanno più motivo di esistere. Q’ non è un clone 
   di Q perché inevitabilmente non potremmo ricostruire l’esatto ordine degli item nella coda originale Q)

specifica
    dati di input: queue q1, q2
    dati di output: queue concat
    precondizione: le code devono esistere
    postcondizione: concat è la concatenazione di q1 e q2

progettazione
    1. crea queue concat
    2. finchè q1 non è vuota, sposta ogni suo elemento in concat
    3. finchè q2 non è vuota, sposta ogni suo elemento in concat
    4. libera lo spazio occupato da q1 e q2
    5. restituisci concat
*/

queue concatenazione(queue q1, queue q2)
{
    item p;
    queue concat;
    concat = newQueue();
    while (!emptyQueue(q1))
    {
        p = dequeue(q1);
        enqueue(p, concat);
    }
    while (!emptyQueue(q2))
    {
        p = dequeue(q2);
        enqueue(p, concat);
    }
    free(q1);
    free(q2);
    return concat;
}

int main()
{
    float len;
    queue q;
    queue *piano_cart;
    q = newQueue();
    q = input_coda_punti(q);

    piano_cart = sottocode(copia_queue(q));
    printf("primo quadrante:\n");
    output_queue(piano_cart[0]);
    printf("secondo quadrante:\n");
    output_queue(piano_cart[1]);
    printf("terzo quadrante:\n");
    output_queue(piano_cart[2]);
    printf("quarto quadrante:\n");
    output_queue(piano_cart[3]);
    
    len = spezzata(q);
    printf("\nlunghezza spezzata: %g\n", len);
    
    q = concatenazione(piano_cart[0], piano_cart[1]);
    q = concatenazione(q, piano_cart[2]);
    q = concatenazione(q, piano_cart[3]);
    printf("\nconcatenazione: \n");
    output_queue(q);
}