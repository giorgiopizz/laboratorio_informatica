//esame
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define K 50
struct punto{
        float m;
        float x;
        float y;
};
typedef struct punto pt;
void printapunto(pt a){
        printf("Il punto è:\nx:%f,\ny:%f,\nm:%f\n\n", a.x, a.y,a.m);
}
void leggivalori(pt punti[]){
        int i;
        //leggo i valori tramite scanf, essendoci k punti, itero la lettura k volte
        for(i=0;i<K;++i){
                printf("Inserisci le coordinate per il punto %i(devono essere del tipo x y m)\n",i+1);
                scanf("%f", &punti[i].x);
                scanf("%f", &punti[i].y);
                scanf("%f", &punti[i].m);
                printapunto(punti[i]);
        }
}
pt cdm(pt punti[]){
        pt cm;
        float x;
        float y;
        float m=0;
        int i;
        for (i=0;i<K;++i){
                m=m+punti[i].m;
                x=x+punti[i].x*punti[i].m;
                y=y+punti[i].y*punti[i].m;
        }
        cm.m=m;
        cm.x=x/m;
        cm.y=y/m;
        return cm;
}
float distanza(pt a, pt b){
        float dist;
        dist=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
        return dist;
}
int minore(pt cm, pt punti[],float s){
        //i indice per il loop e j indice di quanti numeri sono a
        //distanza inferiore di s, infatti all'inizio è 0
        int i, j=0;
        for(i=0;i<K;++i){
                printf("la distanza è: %f\n",distanza(cm, punti[i]));
                printf("la differenza è: %f\n",distanza(cm, punti[i])-s);
                if(distanza(cm, punti[i])<=s){
                        ++j;
                }
        }
        return j;
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
        //definisco array di punti
        pt punti[K];
        printf("Benvenuto!\nInserisci i punti materiali di cui calcolerò il centro di massa:\n");
        //li leggo
        for(i=0;i<K;++i){
                printf("Inserisci le coordinate per il punto %i(devono essere del tipo x y m)\n",i+1);
                scanf("%f %f %f", &punti[i].x, &punti[i].y, &punti[i].m);
                printapunto(punti[i]);
        }
        //leggivalori(punti);
        //definisco il centro di massa(che è un punto) e lo calcolo
        pt cm;
        cm=cdm(punti);
        printf("Il centro di massa trovato è:\n");
        printapunto(cm);
        printf("Il numero di punti a distanza inferiore di s è:%i\n",minore(cm,punti,s));
}
