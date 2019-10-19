#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct elm{
    int c;
    struct elm * p;
};
typedef struct elm elm;

void inbasedue(char basedieci[], char string[]){
    elm * t;
    elm * l;
    l=t;
    t=NULL;
    int quoz=atoi(basedieci);
    int resto=0;
    int i=0;
    while(quoz!=0){
        resto=quoz%2;
        quoz=quoz/2;
        if(t==NULL){
            t=(elm*)malloc(sizeof(elm));
            t->c=resto;
            t->p=NULL;
        }
        else{
            //aggiungo in testa
            l=(elm*)malloc(sizeof(elm));
            l->c=resto;
            l->p=t;
            t=l;
        }
    }
    l=t;
    i=0;
    while(l!=NULL){
        string[i]=l->c+'0';
        l=l->p;
        ++i;
    }
    string[i]='\0';
}
int lunghezza(char string[]){
    int i=0;
    while(string[i]!='\0'){
        ++i;
    }
    return i;
}
void inbasedieci(char basedue[], char string[]){
    int strlen=lunghezza(basedue);
    int x;
    int y=0;
    for (x=0;x<strlen;++x){
        y=y+(int)((basedue[x]-'0')*pow(2,strlen-x-1));
    }
    sprintf(string,"%d",y);

}
int main(){

    char strin[100];
    inbasedieci("1010", strin);
    inbasedue(strin, strin);
    printf("%s\n",strin );
}
    //printf("%s", inbasedue("10"));
