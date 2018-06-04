//prova del char pointer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct elm{
    int c;
    struct elm * p;
};
typedef struct elm elm;

void inbasedue(char * basedieci ,char * basedue){
    elm * t;
    elm * l;
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
        basedue[i]=l->c+'0';
        l=l->p;
        ++i;
    }
    basedue[i]='\0';

}
int lunghezza(char string[]){
    int i=0;
    while(string[i]!='\0'){
        ++i;
    }
    return i;
}
void inbasedieci(char basedue[], char * basedieci){
    int strlen=lunghezza(basedue);
    int x;
    int y=0;
    for (x=0;x<strlen;++x){
        y=y+(int)((basedue[x]-'0')*pow(2,strlen-x-1));
    }
    sprintf(basedieci,"%d",y);

}
int main(){
	/*char * basedue;
	char basedieci[]="64";
	basedue=(char *) malloc(((int)(log2(atoi(basedieci))+1))*sizeof(char));
	inbasedue(basedieci,basedue);*/
	char basedue[]="00000000";
	char * basedieci;
	basedieci=(char*)malloc(((int)(log10(pow(2,lunghezza(basedue)))+1))*sizeof(char));
	inbasedieci(basedue, basedieci);
	printf("Ho allocato %i caselle\n",(int)(log10(pow(2,lunghezza(basedue)-1))+1));
	printf("%s", basedieci);
}
