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
void swap(char *s1, char *s2)
{
	char temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
void ordina(char *s, int n)
{
	int i, j, scambi=0;
	for (i = 0; i < n - 1; i++)
	{
        for (j = i + 1; j < n; j++)
        {
            if (s[i] > s[j])
		    {
			    swap(&s[i], &s[j]);
		    }
        }
	}
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

    ordina(nomecognome[0], strlen(nome));
    ordina(nomecognome[1], strlen(cognome));
    printf("nome e cognome ordinati: %s %s\n", nomecognome[0], nomecognome[1]);
    return 0;
}