#include <stdio.h>
#include <stdbool.h>
float valoreassoluto(float a){
    if(a>=0){
        return a;
    }
    else{
        return -a;
    }
}
bool minore(float a, float b){
    //se il valore assoluto del primo numero è minore del valore assoluto del secondo allora la funzione ritorna vero
    if(valoreassoluto(a)<valoreassoluto(b)){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n,i=0;
    float x,eps;
    printf("Inserisci la dimensione del vettore:");
    scanf("%i",&n);
    float vect[n];
    printf("Inserisci il reale x ed epsilon(separati da un invio): ");
    scanf("%f",&x);
    scanf("%f",&eps);
    while(i<n){
        printf("Inserisci un valore: ");
        scanf("%f",&vect[i]);
    }
    i=0;
    while(i<n){
			if(minore((x-vect[i]),eps)){
				printf("La distanza tra %f e il valore %f è minore di %f",x, vect[i], eps);
			}
   			else{
				printf("La distanza tra %f e il valore %f è maggiore di %f",x, vect[i], eps);
			}
    }
}
