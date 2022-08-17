#include <stdio.h>

/*
Triangolo di Tartaglia: 
    si consideri una matrice triangolare T, rappresentante il famoso triangolo di Tartaglia, i cui valori, 
    identificati dal loro numero di riga e di colonna, sono definiti nel seguente modo:
    BASE: T(a,1) = 1 (prima colonna) e T(a,a) = 1 (diagonale principale)
    PASSO: T(a,b) = T(a-1,b-1) + T(a-1,b)
    Si scriva una funzione ricorsiva che, utilizzando la definizione sopra, permetta di calcolare
    il valore di un generico elemento del triangolo di Tartaglia, indicato dall’indice di riga
    e colonna della matrice che rappresenta il triangolo.
    NOTA. Per ragioni pratiche, gli indici partono da 1 e non da zero.
*/

int tartaglia(int a, int b)
{
    if (b == 1 || a == b) //caso base: prima colonna e diagonale principale
    {
        return 1;
    }
    else
    {
        return tartaglia(a-1, b-1) + tartaglia(a-1, b); //passo ricorsivo
    }
}

int main(void)
{
    int riga, colonna, tart;
    printf("inserisci riga: ");
    scanf("%d", &riga);
    printf("inserisci colonna: ");
    scanf("%d", &colonna);
    
    tart = tartaglia(riga, colonna);
    printf("il valore in posizione (%d,%d) è %d\n", riga, colonna, tart);
    return 0;
}