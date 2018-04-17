#include <stdio.h>
#define N 3
int main(){
        int vect[N];
        int n=0,z;
        int minimo, x;
        while(n<N){
                scanf("%i",&vect[n]);
                if(n==0){
                        minimo=vect[n];
                        x=0;
                }
                else{
                        if(minimo<vect[n]){
                                minimo=vect[n];
                                x=n;
                        }
                }
                ++n;
        }
        if(x!=0){
                int primo=vect[0];
                vect[0]=minimo;
                vect[x]=primo;
        }
        for(z=1;z<N-1;++z){
                for(n=z;n<N;++n){
                        if(n==z){
                              minimo=vect[n];
                              x=z;
                        }
                        else{
                              if(minimo<vect[n]){
                                      minimo=vect[n];
                                      x=n;
                              }
                        }
                }
                if(x!=z){
                        int primo=vect[z];
                        vect[z]=minimo;
                        vect[x]=primo;
                }
                if(z==N-2){
                        for(n=0;n<N;++n){
                              printf("Il valore alla %i-a posizione è: %i\n", n+1, vect[n]);
                        }
                }
         }
        
}          