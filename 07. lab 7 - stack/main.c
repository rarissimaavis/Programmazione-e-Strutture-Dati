#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

/*
1. creazione stack di interi
   riempire uno stack con dati interi positivi presi da tastiera
   l'inserimento nello stack termina quando viene digitati -1

specifica
    dati di input: stack s
    dati di output: stack s'
    precondizione: x > 0 OR x = -1
    postcondizione: s' contiene gli interi positivi inseriti da tastiera 

progettazione
    1. inserisci un intero nell'item x
    2. finchè non viene inserito il valore -1, esegui il push dell'item x nello stack s
       e aggiorna il valore di x inserendo un nuovo intero
    3. restituisci s
*/

stack input_stack(stack s)
{
    int x;
    input_item(&x);
    while (x != -1)
    {
        push(x, s);
        input_item(&x);
    }
    return s;
}

stack copia_stack(stack s)
{
    stack copia, tmp;
    copia = newStack();
    tmp = newStack();
    while (!emptyStack(s))
    {
        push(top(s), tmp);
        pop(s);
    }
    while(!emptyStack(tmp))
    {
        push(top(tmp), copia);
        push(top(tmp), s);
        pop(tmp);
    }
    free(tmp);
    return copia;
}

/*
2. inversione
   creare una copia dello stack i cui elementi risultano invertiti
   (entrambi gli stack devono continuare ad esistere dopo il processo di copia)

specifica
    dati di input: stack s
    dati di output: stack inv
    postcondizione: inv contiene gli elementi di s in ordine inverso

progettazione
    1. crea lo stack inv e lo stack copia dello stack s
    2. finchè lo stack di partenza s non è vuoto, esegui il push del suo elemento top nello stack inv
       ed eliminalo dallo stack s
    3. libera la memoria occupata da s (ormai vuoto)
    4. restituisci inv
*/

stack inverti_stack(stack s)
{
    stack inv, copia;
    inv = newStack();
    copia = newStack();
    copia = copia_stack(s);
    while(!emptyStack(copia))
    {
        push(top(copia), inv);
        pop(copia);
    }
    free(copia);
    return inv;
}

/*
3. merge
   con i due stack appena prodotti, si realizzi un terzo stack per mezzo di una funzione void append(stack1, stack2)
   i cui elementi sono ottenuti come combinazione dei due stack secondo l'ordine con il quale 
   vengono passati in input alla funzione 

specifica
    dati di input: stack s1, stack s2
    dati di output: stack mer
    postcondizione: mer contiene gli elementi di s1 ed s2 in ordine

progettazione
    1. crea stack gli mer, inv_s1 inverso di s1 e inv_s2 inverso di s2
    2. finchè inv_s2 non è vuoto, esegui il push del suo primo elemento in mer ed eliminalo da inv_s2
    3. finchè inv_s1 non è vuoto, esegui il push del suo primo elemento in mer ed eliminalo da inv_s1
    4. libera la memoria occupata da inv_s1 e inv_s2
    5. restituisci mer
*/

stack merge(stack s1, stack s2)
{
    stack mer, inv_s1, inv_s2;
    mer = newStack();
    inv_s1 = inverti_stack(s1);
    inv_s2 = inverti_stack(s2);
    while(!emptyStack(inv_s2))
    {
        push(top(inv_s2), mer);
        pop(inv_s2);
    }
    while(!emptyStack(inv_s1))
    {
        push(top(inv_s1), mer);
        pop(inv_s1);
    }
    free(inv_s1);
    free(inv_s2);
    return mer;
}

/*
4. estrazione
   lo stack non consente di estrarre un elemento che si trova al di sotto del top
   con il nostro stack S'' di numeri prodotto dall'esercizio precedente immaginiamo di voler cancellare
   tutti gli elementi corrispondenti ad un n dato in input
   (la funzione non deve creare un secondo stack bensì restituire S'' con gli elementi rimossi) 

specifica
    dati di input: stack s, item el
    dati di output: stack s'
    postcondizione: s' è s senza gli elementi el

progettazione
    1. crea stack tmp
    2. finchè s non è vuoto, se il suo primo elemento è diverso dall'elemento cercato, esegui il push in tmp
       ed eliminalo da s, altrimenti se è uguale ad el eliminalo soltanto
    3. finchè tmp non è vuoto, esegui il push del suo primo elemento in s ed eliminalo da tmp
    4. libera la memoria occupata da tmp
    5. restituisci s
*/

stack estrai(stack s, item el)
{
    stack tmp;
    tmp = newStack();
    while (!emptyStack(s))
    {
        if (!eq(el, top(s)))
        {
            push(top(s), tmp);
            pop(s);
        }
        else
        {
            pop(s);
        }
    }
    while (!emptyStack(tmp))
    {
        push(top(tmp), s);
        pop(tmp);
    }
    free(tmp);
    return s;
}

void output_stack(stack s)
{
    while (!emptyStack(s))
    {
        output_item(top(s));
        printf(" ");
        pop(s);
    }
    printf("\n");
}

int main()
{
    stack s, inv, mer, est;
    s = newStack();
    input_stack(s);

    inv = inverti_stack(s);
    mer = merge(copia_stack(s), copia_stack(inv));
    est = estrai(copia_stack(mer), 3); 

    printf("\n1. stack iniziale: ");
    output_stack(s);
    printf("2. stack invertito: ");
    output_stack(inv);
    printf("3. stack merge: ");
    output_stack(mer);
    printf("4. stack estrazione: ");
    output_stack(est);
    return 0;
}