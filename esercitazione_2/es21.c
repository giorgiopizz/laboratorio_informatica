#include <stdio.h>
int main(){
        int x,y, somma;
        printf("Inserisci il primo numero di cui calcolero la somma: ");
        scanf("%i",&x);
        printf("Inserisci il secondo numero: ");
        scanf("%i",&y);
        somma=x+y;
        if(somma%2==0){
                printf("La somma è pari ed è: %i\n ",somma);
        }
        else{
                printf("La somma è dispari ed è: %i\n", somma);
        }
}