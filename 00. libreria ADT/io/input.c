list input_list(list l)
{
    int n, el;
    printf("quanti interi vuoi inserire nella lista? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        input_item(&el);
        l = consList(el, l);
    }
    return l;
}

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

queue input_queue(queue q)
{
    int x;
    input_item(&x);
    while (x != -1)
    {
        enqueue(x, q);
        input_item(&x);
    }
    return q;
}

Btree input_Btree(int *a, int i, int numel)
{
    if (i >= numel)
    {
        return NULL;
    }
    return consBtree(a[i], input_Btree(a, 2*i+1, numel), input_Btree(a, 2*i+2, numel));
}

BST input_BST(int *a, int numel)
{
    BST T = newBST();
    for (int i = 0; i < numel; i++)
    {
        T = insert(T, a[i]);
    }
    return T;
}

PQueue input_PQ(int *a, int numel)
{
    PQueue pq = newPQ();
    for (int i = 0; i < numel; i++)
    {
        insert(pq, a[i]);
    }
    return pq;
}