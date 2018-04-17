#include <stdio.h>
#define N 3
int main(){
        int vect[N];
        int n=0;
        int minimo, x;
        while(n<N){
                //leggo i valori e li inserisco nel vettore
                scanf("%i",&vect[n]);
                if(n==0){
                        //definisco all'inizio del vettore il minimo come il primo elemento
                        minimo=vect[n];
                        x=0;
                }
                else{
                        //controllo se si trova un nuovo minimo
                        if(minimo<vect[n]){
                                minimo=vect[n];
                                x=n;
                        }
                }
                ++n;
        }
        if(x!=0){
                //scambio il primo con il minimo
                int primo=vect[0];
                vect[0]=minimo;
                vect[x]=primo;
        }
        n=0;
        while(n<N){
                printf("Il valore %i è: %i", n, vect[n]);
                ++n;
        }
}
        
        
    
    
            