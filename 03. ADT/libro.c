#include <stdio.h>
#include <stdlib.h>
#include "libro.h"

struct miolibro
{
      char titolo[53];
      char editore[26];
      float prezzo;
      int anno;
};

libro creaLibro(char *t, char* e, float p, int a)
{
      libro l;
      strcpy(l->titolo, t);
      strcpy(l->editore, e);
      l->prezzo = p;
      l->anno = a;
      return l;
}

char *titolo(libro l)
{
      char *t;
      t = calloc(53, sizeof(char));
      strcpy(t, l->titolo);
      return t;
}

char* editore(libro l)
{
      char *e;
      e = calloc(26, sizeof(char);
      strcpy(e, l->editore);
      return e;
}

int anno(libro l)
{
      return l->anno;
}

float prezzo(libro l)
{
      return l->prezzo;
}


float sconto(libro *l, float percentuale)
{
    return (*l)->prezzo-((*l)->prezzo*percentuale/100));
}
