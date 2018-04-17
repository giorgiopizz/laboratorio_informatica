#include <stdio.h>
int main(){
        int x,somma=0,i=1;
        float media;
        printf("Inserisci un numero: ");
        scanf("%i",&x);
        while(x!=0){
                printf("Inserisci un numero: ");
                scanf("%i",&x);
                somma=somma+x*x;
                ++i;        
        }
        media=(float)somma/i;
        printf("La media dei quadrati è: %.1f\nLa somma è: %i", media,somma);
}