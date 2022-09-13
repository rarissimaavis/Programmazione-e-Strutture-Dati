void outputList (list l)
{
    int i = 0;
    item val;
    while (!emptyList(l))
    {
        val = getFirst(l);
        printf("elemento di posizione %d: ", i);
        output_item(val);
        printf("\n");
        l = tailList(l);
        i++;
    }
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

void output_queue(queue q)
{
    while (!emptyQueue(q))
    {
        output_item(dequeue(q));
    }
	printf("\n");
}

void output_Btree(Btree T, int liv)
{
    if (getRoot(T) == NULL) 
    {
	    return;
    }
    else 
    {
        output_Btree(getRoot(figlioDX(T)), liv+1);
        for (int i = 0; i < liv; i++)
        {
    	    printf("   ");
        }
        printf("%d\n", getItem(getRoot(T)));
        output_Btree(getRoot(figlioSX(T)), liv+1);
    }
}

void output_BST(BST T, int liv)
{
    if (getRoot(T) == NULL) 
    {
	    return;
    }
    else 
    {
        output_BST(getRoot(figlioDX(T)), liv+1);
        for (int i = 0; i < liv; i++)
        {
    	    printf("   ");
        }
        printf("%d\n", getItem(getRoot(T)));
        output_BST(getRoot(figlioSX(T)), liv+1);
    }
}

void output_PQ(PQueue q, int numel) 
{
    for (int i = 1; i <= numel; i++) 
	{
        output_item(getMax(q));
		deleteMax(q);
    }
	printf("\n");
}