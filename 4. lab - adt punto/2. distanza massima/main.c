#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

/*
traccia 
    realizzare una funzione che prende in ingresso una sequenza di punti e restituisce i due punti 
    a distanza massima della sequenza. Mostrare su standard output sia i due punti che la loro distanza

specifica
    dati di ingresso: una sequenza sp di punti
    dati di uscita: p1 e p2 
    precondizione: sp non vuota
    postcondizione: p1 e p2 sono i due punti a distanza massima dmax

progettazione
    1. input numero di punti n
    2. crea array p di punti di dimensione n
    3. input n punti e carica in array p
    4. calcola i due punti p1 e p2 in p a distanza massima 
    5. output p1, p2 e dmax

raffinamento: progettazione funzione distanza_max
    1. inizializza dmax a 0
    2. per ogni punto, considera la sua distanza da tutti i punti successivi
    3. se la distanza è maggiore della distanza massima attuale, aggiorna il valore di dmax
       e inserisci i punti nell'array pmax
    4. restituisci dmax
*/

void input_punti(punto p[], int n)
{
	int i;
	float x, y;
	for (i = 0; i < n; i++)
	{
		printf("Ascissa punto %d: ", i);
		scanf("%f", &x);
		printf("Ordinata punto %d: ", i);
		scanf("%f", &y);
		p[i] = creapunto(x, y);
	}
}

float distanza_max(punto p[], int n, punto pmax[])
{
    int i, j;
    float dmax = 0;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (distanza(p[i], p[j]) > dmax)
            {
                dmax = distanza(p[i], p[j]);
                pmax[0] = p[i];
                pmax[1] = p[j];
            }
        }
    }
    return dmax;
}

int main()
{
    int n;
    float dmax;
    punto *p, pmax[2];
  
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    p = malloc(n*sizeof(punto));
    input_punti(p, n);

    dmax = distanza_max(p, n, pmax);

    printf("I punti a distanza massima (%g) sono:\n", dmax);	
    stampa(pmax[0]);
    stampa(pmax[1]);
    return 0;
}

