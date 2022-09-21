//esame 140922

//1. conta nodi fino al livello k

int conta_fino_a_k(Btree t, int k)
{
    if (emptyBtree(t) || k <= 0)
    {
        return 0;
    }
    if (k > 0)
    {
        return 1 + conta_fino_a_k(figlioSX(t), k-1) + conta_fino_a_k(figlioDX(t), k-1);
    }
}


//2. rimuovi minimo da uno stack

void rimuovi_minimo(stack s)
{
    stack tmp = newStack();
    item curr, min = top(s);
    while (!emptyStack(s))
    {
        curr = top(s);
        if (curr < min)
        {
            min = curr;
        }
        push(curr, tmp);
        pop(s);
    }
    while (!emptyStack(tmp))
    {
        curr = top(tmp);
        if (min != curr)
        {
            push(curr, s);
        }
        pop(tmp);
    }
    free(tmp);
}


//3. rimuovi secondo minimo da una lista 

item secondo_minimo(list l)
{
    list tmp = newList();
    item curr, min = getFirst(l), min2 = getFirst(l);
    while (!emptyList(l))
    {
        curr = getFirst(l);
        if (curr < min)
        {
            min = curr;
        }
        tmp = consList(curr, tmp);
        l = tailList(l);
    }
    while (!emptyList(tmp))
    {
        curr = getFirst(tmp);
        if (curr > min && curr < min2)
        {
            min2 = curr;
        }
        l = consList(curr, l);
        tmp = tailList(tmp);
    }
    free(tmp);
    return min2;
}