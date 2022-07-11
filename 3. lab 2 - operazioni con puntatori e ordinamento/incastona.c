#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
void *xcalloc(size_t n, size_t size) 
{
    void *result;
    if ((result = calloc(n, size)) == NULL)
    {
        fprintf(stderr, "errore di allocazione memoria\n");
        exit(-1);
    }
    return result;
}
void *xrealloc(void *p, size_t nbytes)
{
    void *result;
    if ((result = realloc(p, nbytes)) == NULL)
    {
        fprintf(stderr, "errore di riallocazione memoria\n");
        exit(-1);
    }
    return result;
}
char *incastona(char *s1, char *s2)
{
    int len1, len2, i, j=0;
    len1 = strlen(s1);
    len2 = strlen(s2);
    if (len1 > len2)
    {
        for (i = (len1-len2)/2; i < (len1+len2)/2; i++)
        {
            s1[i] = s2[j];
            j++;
        }
        return s1;
    }
    else if (len2 > len1)
    {
        for (i = (len2-len1)/2; i < (len2+len1)/2; i++)
        {
            s2[i] = s1[j];
            j++;
        }
        return s2;
    }
}
int main(void)
{
    char *sandwich, *nome, *cognome, *nomecognome[2];
    nome = xcalloc(MAX, sizeof(char));
    cognome = xcalloc(MAX, sizeof(char));

    printf("inserisci il nome: ");
    scanf("%s", nome);
    nome = xrealloc(nome, strlen(nome)+1);
    printf("inserisci il cognome: ");
    scanf("%s", cognome);
    cognome = xrealloc(cognome, strlen(cognome)+1);

    nomecognome[0] = nome;
    nomecognome[1] = cognome;

    sandwich = incastona(nomecognome[0], nomecognome[1]);
    printf("il risultato dell'incastonamento è: %s\n", sandwich);
    return 0;
}