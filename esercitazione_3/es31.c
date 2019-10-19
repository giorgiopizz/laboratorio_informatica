#include <stdio.h>
float potenza(float numero, int n){
        float risultato;//definisco la potenza 0
        if(n==0){
                risultato=1;
        }
        //definisco la potenza 1
        else if(n==1){
                risultato=numero;
        }
        //definisco la potenza n ricorsivamente
        else if(n>0){
                risultato=potenza(numero*numero, n-1);        
        }
        return risultato; 
}
int main(){
        float x;
        int n;
        printf("Inserisci il reale: ");
        scanf("%f", &x);
        printf("Inserisci la potenza desiderata: ");
        scanf("%i",&n);
        printf("La potenza %i-esima è: %f", n, potenza(x,n));
}
     
     