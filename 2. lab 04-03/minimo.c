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
char minimo(char *a)
{
    char min = a[0];
    int len = strlen(a);
    for (int i = 1; i < len; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
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
    nome = realloc(nome, strlen(nome)+1);
    printf("inserisci il cognome: ");
    scanf("%s", cognome);
    cognome = realloc(cognome, strlen(cognome)+1);

    minn = minimo(nome);
    minc = minimo(cognome);
    printf("minimo del nome: %c, minimo del cognome: %c\n", minn, minc);
    return 0;
}