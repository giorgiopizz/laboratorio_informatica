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
        /*
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
        }*/

        scanf("%i",&valiniz[d]);
        printf("Il numero immesso è: %i\n",valiniz[d]);
        ++d;
        //pulisco numero
    }
    for(i=0;i<2;++i){
        scanf("\n%c %f",&vettore[i].lettera,&vettore[i].num);
        //scanf("",);
    }
    for (i=0; i<2; ++i) {
        printf("Per il punto %i abbiamo come lettera: %c\ne come numero %f\n", i+1, vettore[i].lettera, vettore[i].num);
    }
    //faccio media
    //deviazione standard
    //errore media
    //divido in k bin
}
