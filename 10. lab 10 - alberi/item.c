#include <stdio.h>
#include "item.h"

int eq(item x, item y)
{
    return x == y;
}

void input_item(item *x)
{
    printf("inserisci un numero: ");
    scanf("%d", x);
} 

void output_item(item x)
{
    printf("%d", x);
}