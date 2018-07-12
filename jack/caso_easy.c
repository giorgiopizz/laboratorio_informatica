#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//quasi sempre richiedono di definire un parametro costante uguale a qualcosa
//in questo caso uguale a trenta
#define K 30

struct punto{
    //i campi della struct
    float x;
    float y;
    char c;
};
void leggi(pnt punti[]){
    int i;
    printf("Inserire i valori: come x y carattere e invio\n");
    for(i=0;i<K;++i){
        printf("Punto %i:\n", i);
        scanf("%f %f %c", &punti[i].x, &punti[i].y, &punti[i].c);    
    }
}
void calcoli(pnt punti[]){
    //funzione che fa dei calcoli
    float ris;
    printf("Il risultato dei calcoli è: %f", ris);
    //la funzione calcoli potrebbe anche essere una non-voi
    //quindi restituire un valore, in questo caso andrebbe 
    //eliminata la printf
}
typedef struct punto pnt;
int main(int argc, char * argv[]){
    //dichiaro il vettore di punti di dimensione K
    pnt points[K];
    //chiamo la funzione per leggere i valori e popolare il vettore
    leggi(points);
    //adesso il vettore contiene tutti i dati, quindi faccio i calcoli
    calcoli(points);
    printf("Fine del programma\n");
}