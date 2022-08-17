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
char *merge(char *s1,char *s2)
{
    char *result;
    result = xcalloc(strlen(s1) + strlen(s2) + 1, 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
void crea(char **nomecognome)
{
    char *nome, *cognome;   
    nomecognome = xrealloc(nomecognome, 3 * sizeof(char*));
    nomecognome[2] = xcalloc(7, sizeof(char));
    strncpy(nomecognome[2], nome, 3);
    nomecognome[2][3] = '\0';
    nomecognome[2] = merge(nomecognome[2], cognome+strlen(cognome)-3);
}
int main(void)
{
    char *result, *nome, *cognome, **nomecognome;
    nome = xcalloc(MAX, sizeof(char));
    cognome = xcalloc(MAX, sizeof(char));
    nomecognome = xcalloc(2, sizeof(char*));

    printf("inserisci il nome: ");
    scanf("%s", nome);
    nome = xrealloc(nome, strlen(nome)+1);
    printf("inserisci il cognome: ");
    scanf("%s", cognome);
    cognome = xrealloc(cognome, strlen(cognome)+1);

    nomecognome[0] = nome;
    nomecognome[1] = cognome;
    
    crea(nomecognome);
    printf("la nuova matrice è: %s %s %s\n", nomecognome[0], nomecognome[1], nomecognome[2]);
    return 0;
}