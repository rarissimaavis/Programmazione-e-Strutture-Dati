struct Libro
{
    char autore[26];
    char titolo[53];
    char editore[26];
    int anno;
}
typedef struct Libro *libro;

libro creaLibro(char *A, char *T, char *E, int AN)
{
    libro L;
    L = malloc(sizeof(struct Libro));
    if (!L) 
    {
        return NULL;
    }
    strcpy(L->autore, A);
    strcpy(L->titolo, T);
    strcpy(L->editore, E);
    L.anno = AN;
    return L;
}

char *autore(libro L)
{
    char *aut;
    aut = calloc (26, sizeof(char));
    if (aut)
    {
        strcpy(aut, L->autore);
    }
    return aut;
}

char *titolo(libro L)
{
    chat *tit;
    tit = calloc(53, sizeof(char));
    if (tit)
    {
        strcpy(tit, L->titolo);
    }
    return tit;
}

char *editore(libro L)
{
    char *edit;
    edit = calloc(26, sizeof(char));
    if (edit)
    {
        strcpy(edit, L->editore);
    }
    return edit;
}

int anno(libro L)
{
    return L->anno;
}