#include <stdio.h>

/*
Algoritmo di Euclide: 
    calcola il massimo comune divisore di due numeri interi positivi. 
    Dati due numeri n ed m, con n<m, si procede sottraendo ripetutamente il numero più piccolo n 
    dal più grande m fino a quando la differenza d tra i due numeri è maggiore di n
    A questo punto si ripete il procedimento con d al posto di n e con n al posto di m, 
    fino a quando la nuova differenza d non eguaglia esattamente n.
    Tale valore è il massimo comun divisore dei due numeri originali.
*/

int euclide(int m, int n)
{
    int d = m - n; 
    if (d == n) //caso base
    {
        return d;
    }
    else if (d < n) //passo ricorsivo se d < n
    {
        return euclide(n, d);
    }
    else //passo ricorsivo se d > n
    {
        return euclide(d, n);
    }
}

int main(void)
{
    int MCD, m, n;

    printf("inserisci un intero positivo: ");
    scanf("%d", &m);
    printf("inserisci un intero positivo < del precedente: "); //precondizione: m > n
    scanf("%d", &n);
    MCD = euclide(m, n); 
    printf("%d\n", MCD);
    return 0;
}
