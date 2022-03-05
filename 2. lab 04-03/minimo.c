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
char minimo(char *s)
{
    char min = s[0];
    int len = strlen(s);
    for (int i = 1; i < len; i++)
    {
        if (s[i] < min)
        {
            min = s[i];
        }
    }
    return min;
}
int main(void)
{
    char minn, minc, *nome, *cognome;
    nome = xcalloc(MAX, sizeof(char));
    cognome = xcalloc(MAX, sizeof(char));

    printf("inserisci il nome: ");
    scanf("%s", nome);
    nome = xrealloc(nome, strlen(nome)+1);
    printf("inserisci il cognome: ");
    scanf("%s", cognome);
    cognome = xrealloc(cognome, strlen(cognome)+1);

    minn = minimo(nome);
    minc = minimo(cognome);
    printf("minimo del nome: %c, minimo del cognome: %c\n", minn, minc);
    return 0;
}