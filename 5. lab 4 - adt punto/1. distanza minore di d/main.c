#include <stdio.h>
#include <stdlib.h>
#include "punto.h"

/*
traccia 
    realizzare una funzione che prende in ingresso una sequenza di punti e un numero reale d 
    e restituisce il numero di coppie m di punti a distanza minore di d

specifica   
    dati di ingresso: una sequenza sp di punti, un numero reale d
    dati di uscita: un intero m
    precondizione: sp non vuota
    postcondizione: m è il numero di coppie di punti p1 e p2 in sp tali che distanza(p1, p2) < d

progettazione
    1. input numero di punti n
    2. crea array p di punti di dimensione n
    3. input n punti e carica in array p
    4. input distanza d
    5. calcola il numero m di coppie in p con distanza minore di d
    6. output m

raffinamento: progettazione funzione coppie_vicine
    1. inizializza m a 0
    2. per ogni punto, considera la sua distanza da tutti i punti successivi
    3. se la distanza è minore di d, incrementa m
    4. restituisci m
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

int coppie_vicine(punto p[], int n, float d)
{
    int i, j, m = 0;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (distanza(p[i], p[j]) < d)
            {
                m++;
            }
        }
    }
    return m;
}

int main()
{
    int n, m;
    float d;
    float ascissa, ordinata;
    punto *p;
  
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    p = malloc(n*sizeof(punto));
    input_punti(p, n);

    printf("Dammi la distanza: ");
    scanf("%f", &d);
  
    m = coppie_vicine(p, n, d);
   
    printf("Le coppie di punti a distanza minore di %g sono %d\n", d, m);	
    return 0;
}
