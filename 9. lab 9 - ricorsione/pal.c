#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 40

/*
Stringa Palindroma: 
    si definisce palindroma quella stringa che può essere letta indifferentemente 
    da sinistra a destra o da destra a sinistra senza che vi sia una differenza. 
    Realizzare una funzione ricorsiva per dire se una parola è palindroma.
    Esempi palindromi:
    · 4 lettere: osso, esse, ebbe, effe, inni
    · 5 lettere: aveva, esose, aerea, radar
    · 7 lettere: ingegni, ossesso, ottetto
*/

void leggi(char s[])
{
	int len;
	fgets(s, MAX_LEN+1, stdin);
	len = strlen(s);
	if (s[len-1] == '\n')
	{
		s[len-1] = '\0';
	}
}
char *leggi_stringa(int maxlen)
{
    char *s, *s1;
    int len;
    s = (char *) malloc(maxlen+1);
    if (!s) 
    {
        return NULL;
    }
    leggi (s);
    len = strlen(s);
    s1 = malloc(len+1);
    if (!s)
    {
        free(s);
        return NULL;
    }
    strncpy(s1, s, len);
    free(s);
    return s1;
}

int palindroma(char s[], int i, int j)
{
    if (j<1) //caso base
    {
        return 1;
    }
    else
    {
        if (s[i] != s[j]) //lettere corrispondenti diverse
        {
            return 0;
        }
        else
        {
            return palindroma(s, i+1, j-1); //passo ricorsivo: lettera successiva
        }
    }
}
int main(void)
{
    int len, pal;
    char *parola;
    printf("inserisci una parola: ");
    parola = leggi_stringa(MAX_LEN+1);
    len = strlen(parola)-1;
    
    pal = palindroma(parola, 0, len);
    if (pal == 1)
    {
        printf("%s è palindroma\n", parola);
    }
    else 
    {
        printf("%s non è palindroma\n", parola);
    }
    return 0;
}