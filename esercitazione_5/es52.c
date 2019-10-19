#include <stdio.h>

float radq(float x, float min, float max){
    float k;//il valore medio
    k=(max+min)/2;
    if(x<1){
        /*se il valore è compreso tra 0 ed 1 non va bene l'algoritmo quindi viene fatta la radice di x moltiplicata per 10^4 e la radice divisa per 10^2*/
        return radq(x*10000,1,x*10000)/100;
    }
    else{
        if(((max-min)/2)<0.0001||k*k==x){
            return k;
        }
        else if(k*k<x){
            return radq(x,k,max);
        }
        else if(k*k>x){
            return radq(x,min,k);
        }
        else{
            return 0;
        }
    }
}
float radice(float x){
    return radq(x,1,x);
}
float distanza(float x,float y,float a, float b){
    float dist,distq;
    distq=((x-a))*((x-a))+((y-b))*((y-b));
    dist=radice(distq);
    return dist;
}
float norma(float x, float y){
    float dist;
    dist=(x*x+y*y);
    return radice(dist);
}
int main(){
    struct punto{
        char a;
        float x;
        float y;
    } primo, secondo;
    printf("Inserisci il carattere per il punto primo: ");
    scanf("%c",&primo.a);
    printf("Inserisci la x per il punto primo: ");
    scanf("%f",&primo.x);
    printf("Inserisci la y per il punto primo: ");
    scanf("%f",&primo.y);
    printf("Inserisci il carattere per il punto secondo: ");
    scanf(" %c",&secondo.a);
    printf("Inserisci la x per il punto secondo: ");
    scanf("%f",&secondo.x);
    printf("Inserisci la y per il punto secondo: ");
    scanf("%f",&secondo.y);
    printf("La distanza tra il punto %c e il punto %c è: %.3f\n",primo.a,secondo.a, distanza(primo.x,primo.y,secondo.x,secondo.y));
    printf("La norma del vettore associato al punto %c è: %.3f\n", primo.a, norma(primo.x,primo.y));
    printf("La norma del vettore associato al punto %c è: %.3f\n", secondo.a, norma(secondo.x,secondo.y));
}
