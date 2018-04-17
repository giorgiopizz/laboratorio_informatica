#include <stdio.h>
#include <stdbool.h>
bool primo(int numero){
        int n=2;
        bool risultato = true;
        while(n<numero){
                //finchè non trovo un valore che divide il numero, il risultato è vero
                if(numero%n==0){
                        risultato=false;
                        break;
                }
                ++n;
        }
        return risultato;
}
void primiprima(int k){
        int n=1;
        while(n<k){
                if(primo(n)){
                        printf("Il numero %i è primo\n", n);
                }
                n++;
       }
}
int main(){
        int k;
        scanf("%i", &k);
        primiprima(k);
}