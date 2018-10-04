#include <stdio.h>
#include <stdlib.h>
#include "math.h"
//#include "time.h"

#define DIST 1
#define PI 3.141593
#define PREC 1000000
struct passo{
    float distanza;
    float angolo;
};
typedef struct passo passo;

void generoPercorsi(passo passi[], int k){
    //la riga seguente fa in modo che il seme continui a cambiare
    //altrimenti avendo seme fissato ad ogni esecuzione del programma
    //i numeri casuali sono sempre gli stessi. Per fare ciò uso time(0) e la libreria time
    //ma non avendola trattata durante il corso ho deciso di non includerla.
    //srand((unsigned int)time(0));
    srand(1322);
    for(int i=0;i<k;++i){
        //la distanza deve essere compresa tra 0 e 1
        //essendo rand() un numero intero faccio in modo
        //che sia compreso tra 0 e 1000001, dividendolo poi per 1000000
        //avendo una precisione di un milionesimo, si può anche avere
        //100 al posto di un milione avendo la precisione di un centesimo.
        //Così facendo può uscire una distanza uguale a 1.
        passi[i].distanza=(float)(rand()%(DIST*PREC+1))/PREC;
        //discorso analogo per l'angolo che deve essere compreso
        //tra 0 e 2 pi greco incluso. Faccio in modo che rand() sia
        //compreso tra 0 e 6283187 così da poter far uscire 2*PI*1000000
        passi[i].angolo=(float)(rand()%((int)(2*PI*PREC+1)))/PREC;
        printf("la distanza è di %f e l'angolo è di %f\n", passi[i].distanza, passi[i].angolo);
    }
}
void stampoPercorsi(passo passi[], int k, float x, float y){
    //xprov e yprov sono gli spostamenti lungo le x e y del passo in esame
    //xfin e yfin sono gli spostamenti complessivi partendo dall'origine
    //alla fine del ciclo xfin e yfin saranno la posizione finale del punto
    float xprov, yprov, xfin=x, yfin=y, dist;
    for(int i=0;i<k;++i){
        xprov=passi[i].distanza*cos(passi[i].angolo);
        yprov=passi[i].distanza*sin(passi[i].angolo);
        xfin=xfin+xprov;
        yfin=yfin+yprov;
    }
    printf("Il punto ha raggiunto la posizione finale (%f,%f)\n",xfin, yfin);
    //ho così calcolato la posizione finale
    for(int i=(k-1);i>=0;--i){
        xprov=passi[i].distanza*cos(passi[i].angolo);
        yprov=passi[i].distanza*sin(passi[i].angolo);
        xfin=xfin-xprov;
        yfin=yfin-yprov;
        printf("Il punto ha raggiunto la posizione (%f, %f)\n",xfin, yfin);
    }
}
int main(){
    //k è il numero di passi da eseguire
    int k;
    //x e y sono le coordinate iniziali
    float x, y;
    printf("Inserisci i valori iniziali(per primo k seguito dall'ascissa e dall'ordinata)\n");
    //leggo i valori da standard input
    scanf("%i %f %f", &k, &x, &y);
    passo passi[k];
    //genero i percorsi
    generoPercorsi(passi,k);
    //stampo i percorsi
    stampoPercorsi(passi, k, x, y);
}
