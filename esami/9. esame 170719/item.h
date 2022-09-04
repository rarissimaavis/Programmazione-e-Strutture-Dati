typedef int key;

#define NULLkey 0

void input_key(key *x); //inserisce una key 
void output_key(key x); //mostra in output la key x
int eq(key x, key y); //controlla se due key sono uguali
int minore(key x, key y); //verifica se x<y
int maggiore(key x, key y); //verifica se x>y