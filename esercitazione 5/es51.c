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
int minore(float a, float b){
    //se il valore assoluto del primo numero è minore del valore assoluto del secondo allora la funzione ritorna vero
    /*Si è riscontrato un problema in questo punto: si è assunto che la funzione minore dovesse
    determinare quando il valore assoluto fosse minore e non minore uguale dell'altro valore
    assoluto. Con differenze molto vicine ad epsilon e negative il confronto tra float non andava
     a buon fine quindi si è ritenuto più opportuno e preciso confrontare i float moltiplicati per
     mille e approssimati a numeri interi*/
    if((int)(10*10*10*(valoreassoluto(a)-valoreassoluto(b)))<0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n,i=0;
    float x,eps;
    printf("Inserisci la dimensione del vettore: ");
    scanf("%i",&n);
    float vect[n];
    printf("Inserisci il reale x ed epsilon(separati da un invio): ");
    scanf("%f",&x);
    scanf("%f",&eps);
    while(i<n){
        printf("Inserisci un valore: ");
        scanf("%f",&vect[i]);
        ++i;
    }
    i=0;
    while(i<n){
			if(minore((x-vect[i]),eps)){
				printf("La distanza tra %f e il valore %f è MINORE di epsilon(%f)\n",x, vect[i],eps);
			}
   			else{
				printf("La distanza tra %f e il valore %f è MAGGIORE di epsilon(%f)\n",x, vect[i],eps);
			}
			++i;
    }
}
