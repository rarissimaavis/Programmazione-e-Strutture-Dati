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
void inverti (char **s)
{
    char *temp;
    temp = xcalloc(strlen(s[0])+1, 1);
    strcpy(temp, s[0]);
    strcpy(s[0], s[1]);
    strcpy(s[1], temp);
    free(temp);
}
int main(void)
{
    char *nome, *cognome, *nomecognome[2];
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

    inverti(nomecognome);
    printf("la matrice invertita è: %s %s\n", nomecognome[0], nomecognome[1]);
    return 0;
}