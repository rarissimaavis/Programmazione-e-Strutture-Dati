#include <stdio.h>

/*
N-esimo quadrato: 
    l’n-esimo numero quadrato n^2 si può esprimere come la somma dei primi n numeri dispari.
    ossia 5^2 = 25 = 1+3+5+7+9
    Implementare una soluzione ricorsiva per il calcolo del quadrato di un numero intero n 
    sull'osservazione che la regola di cui sopra si può vedere così: n^2 = (n-1)^2 + (2n-1)
*/

int nquad(int n)
{
    if (n == 0) //caso base: se n vale 0 allora il suo quadrato è 0
    {
        return 0;
    }
    else if (n < 0) //se n è negativo calcolo il quadrato del suo opposto
    {
        return nquad(-n);
    }
    else
    {
        return nquad(n-1) + 2*n - 1; //passo ricorsivo: il quadrato è uguale al quadrato di n-1 più 2n-1
    }
}

int main(void)
{
    int qn, n;
    printf("inserisci un intero da elevare al quadrato: ");
    scanf("%d", &n);
    
    qn = nquad(n);
    printf("il quadrato di %d è %d\n", n, qn);
    return 0;
}