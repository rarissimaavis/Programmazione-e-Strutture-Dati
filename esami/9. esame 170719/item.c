#include <stdio.h>
#include "item.h"

void input_key(key *x)
{
    printf("inserisci un numero: ");
    scanf("%d", x);
} 

void output_key(key x)
{
    printf("%d ", x);
}

int eq(key x, key y)
{
    return x == y;
}

int minore(key x, key y)
{
  return x < y;
}

int maggiore(key x, key y)
{
  return x > y;
}