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

    printf("\nrev:\n");
    list rev = newList();
    rev = reverseList_ric(l, rev);
    outputList(rev);
}