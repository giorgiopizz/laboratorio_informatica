#include <stdio.h>
int main(){
        int i, x, somma=0;
        float media;
        for(i=0;i<10,++i){
                printf("Inserisci il %i-o numero: ",i+1);
                scanf("%i",&x);
                somma=somma+x;
        }
        media=(float)somma/10;
        printf("La media è: %.1f\nLa somma è: %i\n",media,somma);
}