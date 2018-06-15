//esame3
//si usa una lista concatenata per immagazzinare i punti
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define K 3
struct punto{
        float m;
        float x;
        float y;
};
typedef struct punto pt;
struct elm{
        pt punto;
        struct elm * prox;
};
typedef struct elm elm;
void printapunto(pt a){
        printf("Il punto è:\nx:%f,\ny:%f,\nm:%f\n\n", a.x, a.y,a.m);
}
void printalista(elm * t){
        while(t!=NULL){
                printapunto(t->punto);
                t=t->prox;
        }
}
elm * elemento(pt point){
        elm * p;
        p=(elm *) malloc(sizeof(elm));
        if(p!=NULL){
                exit(EXIT_FAILURE);
        }
        p->punto=point;
        p->prox=NULL;
        return p;
}
elm * addback(elm * t, pt punto){
        elm * l;
        elm * new;
        new=elemento(punto);
        if(t!=NULL){
                l=t;
                while(l->prox!=NULL){
                        l=l->prox;
                }
                l->prox=new;
        }
        else{
                t=new;
        }
        return t;
}
elm * leggivalori(elm * t){
        pt punto;
        //leggo i valori tramite scanf, essendoci k punti, itero la lettura k volte
        int i;
        for(i=0;i<K;++i){
                printf("Inserisci le coordinate per il punto %i\n",i+1);
                scanf("%f %f %f", &punto.x, &punto.y, &punto.m);
                printapunto(punto);
                t=addback(t, punto);
        }
        printalista(t);
        return t;
}
pt cdm(elm * t){
        pt cm;
        //xm e ym sono rispettivamente la sommatoria di x*m e y*m
        float xm=0;
        float ym=0;
        float m=0;
        elm * l=t;
        while(l!=NULL){
                m=m+l->punto.m;
                xm=xm+l->punto.x*l->punto.m;
                printf("xm è: %f\n", xm);
                ym=ym+l->punto.y*l->punto.m;
                l=l->prox;
        }
        cm.m=m;
        //la x e la y del centro di massa sono definite come la sommatoria di x*m/M
        cm.x=xm/m;
        cm.y=ym/m;
        return cm;
}
float distanza(pt a, pt b){
        float dist;
        dist=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
        return dist;
}
int minore(pt cm, elm * t,float s){
        //i indice per il loop e j indice di quanti numeri sono a
        //distanza inferiore di s, infatti all'inizio è 0
        int i, j=0;
        elm * l=t;
        while(l!=NULL){
                printf("la distanza è: %f\n",distanza(cm, l->punto));
                printf("la differenza è: %f\n",distanza(cm, l->punto)-s);
                if(distanza(cm, l->punto)<s){
                        ++j;
                }
                l=l->prox;
        }
        return j;
}
elm * libera(elm * t){
        //libero la lista dall'ultimo elemento fino al primo
        //funzione ricorsiva che elimina l'ultimo elemento della lista
        if(t->prox!=NULL){
                elm * l=t;
                while(l->prox->prox!=NULL){
                        l=l->prox;
                }
                free(l->prox);
                l->prox=NULL;
                t=libera(t);
        }
        else{
                //in questo caso basta eliminare t
                free(t);
                t=NULL;
        }
	return t;
}
int main(int argc, char * argv[]){
        //dichiaro la variabile s di cui sarà assegnato il valore tramite riga di comando
        float s;
        if (argc != 2) {
                //il programma prende solo un argomento che è s
                exit(EXIT_FAILURE);
        }
        else{
                s = atof(argv[1]);
        }
        int i;
        //definisco la testa di una lista concatenata di punti
        elm * t=NULL;
        printf("Benvenuto!\nInserisci i punti materiali di cui calcolerò il centro di massa\nL'input deve essere del tipo x y m per un punto\n");
        //li leggo
        t=leggivalori(t);
        //definisco il centro di massa(che è un punto) e lo calcolo
        pt cm;
        cm=cdm(t);
        printf("Il centro di massa trovato è:\n");
        printapunto(cm);
        printf("Il numero di punti a distanza inferiore di s è:%i\n",minore(cm,t,s));
        t=libera(t);
}
