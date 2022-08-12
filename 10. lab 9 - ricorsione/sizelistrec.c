/*
Lunghezza di una lista: 
    sappiamo che una lista può avere nel nodo di intestazione il numero di caratteri. 
    Ma supponendo di non avere questa informazione, per conoscere la taglia di una lista bisogna 
    scorrere tutti i suoi elementi. Fornire una soluzione  ricorsiva per contare il numero di 
    elementi presenti in una lista (il tipo di item di cui è composta la lista non è determinante 
    ai fini dell’esercizio) data in input.
*/

int sizeListRec(struct node *head)
{
    if (head == NULL) 
    {
        return 0;
    }
    else
    {
        return 1 + sizeListRec(head->next);
    }
}
