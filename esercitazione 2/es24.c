#include <stdio.h>
int main(){
        int x,massimo;
        printf("Inserisci un numero: ");
        scanf("%i",&x);
        massimo=x;
        while(x!=0){
                printf("Inserisci un numero: ");
                scanf("%i",&x);
                if(massimo<x){
                        massimo=x;
                }
        }
        printf("Il massimo della serie è: %i",massimo);
}