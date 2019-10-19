#include <stdio.h>
#include <stdlib.h>
#define DIM 100
void som(int som[],int primo[], int secondo[]){
    int i;
    if(primo[0]>=secondo[0]){
        int diff=primo[0]-secondo[0];
        for(i=primo[0];i>0;--i){
            if((i-diff)>0){
                som[i]=primo[i]+secondo[i-diff];
            }
            else{
                som[i]=primo[i];
            }
            
        }
        som[0]=primo[0];
    }
    else{
        int diff=secondo[0]-primo[0];
        for(i=secondo[0];i>0;--i){
            if((i-diff)>0){
                som[i]=primo[i-diff]+secondo[i];
            }
            else{
                som[i]=secondo[i];
            }
            
        }
        som[0]=secondo[0];
    }
}
void prodotto(int prod[], int primo[], int secondo[]){
    int i, resto=0, num;
    if(primo[0]>=secondo[0]){
        int diff=primo[0]-secondo[0];
        for(i=primo[0];i>0;--i){
            if((i-diff)>0){
                num=primo[i]*secondo[i-diff]+resto;
                resto=num/10;
                prod[i]=num;
            }
            else{
                som[i]=primo[i];
            }
            
        }
        som[0]=primo[0];
    }
    else{
        int diff=secondo[0]-primo[0];
        for(i=secondo[0];i>0;--i){
            if((i-diff)>0){
                som[i]=primo[i-diff]+secondo[i];
            }
            else{
                som[i]=secondo[i];
            }
            
        }
        som[0]=secondo[0];
    }
}
void printa(int vect[]){
    int i;
    for(i=1;i<=vect[0];++i){
        printf("%i", vect[i]);
    }
}
int main(){
    int primo[DIM], secondo[DIM];
    char c;
    c=getchar();
    int i=1;
    while(c!='\n'){
        if(c>='0' && c<='9'){
            primo[i]=c-'0';
            ++i;
            c=getchar();
        }
    }
    primo[0]=i-1;
    i=1;
    c=getchar();
    while(c!='\n'){
        if(c>='0' && c<='9'){
            secondo[i]=c-'0';
            ++i;
            c=getchar();
        }
    }
    secondo[0]=i-1;
    int somma[DIM];
    som(somma,primo,secondo);
    printa(somma);
}
