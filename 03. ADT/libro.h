/*
specifica sintattica:
    tipo di riferimento: libro
    tipi usati: stringa, intero

specifica semantica:
    il tipo libro è l'insieme delle quadruple (titolo, editore, prezzo, anno)
    dove titolo, editore sono stringhe, prezzo è un reale e anno è un intero
*/
typedef struct miolibro *libro;

/*
specifica sintattica:
    creaLibro(stringa, stringa, reale, intero) -> libro
specifica semantica:
    postcondizione: lb = (tit, ed, pr, an)
*/
libro creaLibro(char *titolo, char *editore, float prezzo, int anno);

/*
specifica sintattica:
    titolo(libro) -> stringa
specifica semantica:
    postcondizione: lb.titolo = tit
*/
char *titolo(libro l);

/*
specifica sintattica:
    editore(libro) -> stringa
specifica semantica:
    postcondizione: lb.editore = ed
*/
char *editore(libro l);

/*
specifica sintattica:
    anno(libro) -> intero
specifica semantica:
    postcondizione: lb.anno = an
*/
int anno(libro l);

/*
specifica sintattica:
    prezzo(libro) -> reale
specifica semantica:
    postcondizione: lb.prezzo = pr
*/
float prezzo(libro l);

/*
specifica sintattica:
    sconto(libro, reale) -> reale
specifica semantica:
    postcondizione: il nuovo prezzo del libro è il prezzo scontato dell'X%
*/
float sconto(libro *l, float percentuale);
