#include <stdio.h>
int fattoriale(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n*fattoriale(n-1);
    }
}
int main(void)
{
    int n, fatt;
    n = 5;
    fatt = fattoriale(n);
    printf("il fattoriale di %d è %d\n", n, fatt);
    return 0;
}