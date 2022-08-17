typedef struct pto *punto;
typedef punto item;

#define NULLITEM 0

/*
specifica sintattica: 
    creapunto(reale, reale) -> punto
specifica semantica: 
    postcondizione: p = (x, y)
*/
punto creapunto(float x, float y); 

/*
specifica sintattica: 
    ascissa(punto) -> reale
specifica semantica:
    postcondizione: il risultato x è il primo elemento della coppia p
*/
float ascissa(punto p);

/*
specifica sintattica: 
    ordinata(punto) -> reale
specifica semantica:
    postcondizione: il risultato y è il secondo elemento della coppia p
*/
float ordinata(punto p);

/*
specifica sintattica: 
    distanza(punto, punto) -> reale
specifica semantica:
    postcondizione: d = sqrt((ascissa(p1)-ascissa(p2))^2-(ordinata(p1)-ordinata(p2))^2)
*/
float distanza(punto p1, punto p2);

void  stampa(punto p);