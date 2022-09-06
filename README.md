# Esercizi Programmazione e Strutture Dati 💻📘
## lab 1: operazioni su array
- **minimo**: alloca dinamicamente nome e cognome e restituisce il carattere di valore minimo di entrambi
- **minimomatr**: come prima ma nome e cognome sono in una matrice e restituisce un array con i due elementi di valore minimo
## lab 2: operazioni con puntatori e ordinamento
- **merge**: prende in input due stringhe e produce una nuova stringa che è il risultato della concatenazione delle due date in input
- **incastona**: la più piccola delle due stringhe va incastonata nella più lunga 
- **inverti**: rimpiazza la stringa del nome con quella del cognome e viceversa
- **crea**: aggiunge una terza stringa alla matrice composta dai primi tre caratteri del nome e gli ultimi tre del cognome
- **insertionsort**: ordina i caratteri del nome e del cognome con l'algoritmo di ordinamento insertion sort
- **bubblesort**: ordina i caratteri del nome e del cognome con l'algoritmo di ordinamento bubble sort
## ADT
- **ADT punto**
- **ADT libro**
## lab 4: ADT punto
- **distanza minore di d**: prende in input una sequenza di punti e un numero reale d e restituisce il numero di coppie m di punti a distanza minore di d
- **distanza massima**: prende in input una sequenza di punti e restituisce i due punti a distanza massima
## lab 6: list
- **cerca elemento**: cerca l'elemento 55 nella lista
- **cerca posizione**: cerca la posizione dell'elemento 25
- **rimuovi centrale**: rimuove dalla lista l'elemento in posizione centrale senza avere la conoscenza a priori della dimensione della lista
## lab 7: stack
- **input stack**: crea uno stack di interi presi da tastiera
- **inverti stack**: crea una copia (funzione copia stack) dello stack i cui elementi sono invertiti
- **merge**: combina gli elementi di due stack secondo l'ordine in cui vengono passati in input alla funzione
- **estrai**: cancella gli elementi corrispondenti ad un n dato in input
## lab 8: queue
- **coda di punti**: crea una coda i cui item sono ADT punto
- **sottocode**: dividi la coda in 4 sottocode corrispondenti ai 4 quadranti del piano cartesiano
- **spezzata**: calcola la lunghezza della spezzata formata dai punti
- **concatenazione**: crea una nuova coda ottenuta per concatenazione delle due date in input
## lab 9: ricorsione
- **euclide**: calcola il massimo comune divisore di due numeri interi positivi con l'algoritmo di Euclide
- **nquad**: calcola l’n-esimo quadrato n^2 come somma dei primi n numeri dispari
- **pal**: verifica se una parola è palindroma
- **sizelistrec**: calcola il numero di elementi in una lista
- **tart**: calcola il valore di un generico elemento del triangolo di Tartaglia
## lab 10: alberi
- **creazione da file**: realizza un albero binario i cui nodi contengono dei numeri letti da file
- **conta foglie**: conta il numero di foglie presenti in un albero 
- **albero speculare**: inverte ciascun nodo sinistro con il nodo destro
- **min/max**: ricerca il nodo con valore minimo e massimo
- **uguaglianza**: verifica se due alberi sono uguali
## lab 11: alberi di ricerca
- **isBST**: verifica se un Btree è un albero binario di ricerca
- **nodi in un intervallo**: stampa in ordine i nodi nell'intervallo [A, B]
- **bilanciato**: costruisce un albero binario di ricerca perfettamente bilanciato
- **nodi ad altezza k**: restituisce i nodi ad altezza k 
- **mediano**: verifica se il nodo di valore U è mediano del sottoalbero di cui è radice
## lab 12: pqueue e heap
- **min/max**: restituisce il valore del nodo massimo e del nodo minimo di un heap
- **incrementa chiave**: modifica un heap sostisuendo la key k con un nuovo valore
- **heapify**: dispone gli elementi di un array in modo tale da corrispondere ad uno heap
- **stack**: simula push e pop
- **merge**: combina due pqueue (senza eliminarle)
## esami
- **010719**: cancFinoItem, fondiDaItem (code)
- **110717**: estraiMaxN, inserMinN (code)
- **170619**: presenteQ, xorQ (code)
- **100418**: cancDaItem, fondiQueue (code)
- **250118**: cancDaItem, fondiDaItem (liste)
- **110917**: cancFinoItem, fondiDaItem (liste)
- **110919**: constrAVL, isAVL (BST)
- **050918**: listKeys, remGreatestKeys (code a priorità)
- **170719**: estraiPriorK, aumentaPrior (code a priorità)
- **150622**: foglieK, pqIncrease, strutturalmenteSimili (Btree, code a priorità, Btree)
- **010722**: conta_figli_sx, canc (Btree, code)
- **140722**: conta_figli_unici, al_centro (Btree, stack)