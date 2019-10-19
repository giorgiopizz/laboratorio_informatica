//
//  main.c
//  bobo
//
//  Created by Giorgio Pizzati on 29/05/18.
//  Copyright © 2018 Giorgio Pizzati. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    struct record{
        char lettera;
        float num;
    };
    struct record vettore[2];
    char c;
    int i, b=0,d=0,j;
    char * numero=NULL;
    int valiniz[3];
    //valiniz[0] è A, valiniz[1] è B...
    for(i=0;i<3;++i){
        numero=(char*)malloc(100*sizeof(char));
        b=0;
        c=getchar();
        if(d!=2){
            while(c!=' '){
                numero[b]=c;
                ++b;
                c=getchar();
            }
        }
        else{
            while(c!='\n'){
                numero[b]=c;
                ++b;
                c=getchar();
            }
        }
        valiniz[d]=atoi(numero);
        printf("Il numero immesso è: %i\n",valiniz[d]);
        ++d;
        //pulisco numero
        for(j=0;j<b;++j){
            numero[j]=0;
        }
        free(numero);
    }
    for(i=0;i<2;++i){
        c=getchar();
        vettore[i].lettera=c;
        numero=(char*)malloc(100*sizeof(char));
        b=0;
        //salto lo spazio
        c=getchar();
        c=getchar();
        while (c!='\n') {
            numero[b]=c;
            ++b;
            c=getchar();
        }
        //converto il numero ad un float
        vettore[i].num=atof(numero);
        for(j=0;j<b;++j){
            numero[j]=0;
        }
        free(numero);
    }
    for (i=0; i<2; ++i) {
        printf("Per il punto %i abbiamo come lettera: %c\n e come numero %f\n", i+1, vettore[i].lettera, vettore[i].num);
    }
    //faccio media
    //deviazione standard
    //errore media
    //divido in k bin
}
