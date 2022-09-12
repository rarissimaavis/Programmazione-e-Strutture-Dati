#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

int main (void)
{
    list l = newList();
    l = input_list(l);
    printf("\nlista:\n");
    outputList(l);

    int mid = get_mid(l, 1);
    printf("\nmid: %d\n", mid);
}
