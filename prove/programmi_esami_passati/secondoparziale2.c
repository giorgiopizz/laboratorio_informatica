#include <stdio.h>
#include <stdlib.h>

struct elm{
    int insegn;
    int voto;
    struct elm * prox;
};
typedef struct elm elm;
struct studente{
    int matricola;
    elm * t;
};
void stampa(struct studente studente[]){
    int i;
    for(i=0;i<2;++i){
        printf("Lo studente %i ha dato i seguenti esami:\n",studente[i].matricola);
        elm * l;
        l=studente[i].t;
        while(l->prox!=NULL){
            printf("%i: %i\n",l->insegn, l->voto);
            l=l->prox;
        }
    }
}
int main() {
    //creo un array per due studenti
    struct studente studente[2];
    //a è il numero letto dallo scanf ogni volta
    int a,i;
    //b è un indice che indica qual è il numero matricola, quale il codice insegnamento e quale il voto
    int b;
    char c;
    int d;
    int j;
    int z=0;
    char * numero;
    for(i=0;i<2;++i){
        z=0;
        b=0;
        //leggi il numero matricola
        numero=(char *)malloc(20*sizeof(char));
        d=0;
        c=getchar();
        while(c!=' '){
            numero[d]=c;
            ++d;
            c=getchar();
        }
        a=atoi(numero);
        //pulisco numero
        j=0;
        while(j<d){
            numero[j]=' ';
            ++j;
        }
        free(numero);
        studente[i].matricola=a;
        studente[i].t=NULL;
        ++b;
        while(z!=-1){
            if(b%2!=0){
                if(studente[i].t==NULL){
                    numero=(char *)malloc(20*sizeof(char));
                    d=0;
                    c=getchar();
                    while(c!=' '){
                        if(c=='0'){
                            z=-2;
                        }
                        if(z==-2&&c=='\n'){
                            z=-1;
                            break;
                        }
                        numero[d]=c;
                        ++d;
                        c=getchar();
                    }
                    a=atoi(numero);
                    //pulisco numero
                    j=0;
                    while(j<d){
                        numero[j]=' ';
                        ++j;
                    }
                    free(numero);
                    studente[i].t=(elm*) malloc(sizeof(elm));
                    studente[i].t->insegn=a;
                }
                else{

                    elm * esame;
                    esame=(elm*)malloc(sizeof(elm));
                    numero=(char *)malloc(20*sizeof(char));
                    d=0;
                    c=getchar();
                    while(c!=' '){
                        if(c=='0'){
                            z=-2;
                        }
                        if(z==-2&&c=='\n'){
                            z=-1;
                            break;
                        }
                        numero[d]=c;
                        ++d;
                        c=getchar();
                    }
                    a=atoi(numero);
                    //pulisco numero
                    j=0;
                    while(j<d){
                        numero[j]=' ';
                        ++j;
                    }
                    free(numero);
                    esame->insegn=a;
                    esame->prox=NULL;
                    //percorro tutta la lista e aggiungo all'ultimo
                    elm * l;
                    l=(elm *)malloc(sizeof(elm));
                    l=studente[i].t;
                    while(l->prox!=NULL){
                        l=l->prox;
                    }
                    l->prox=esame;
                }
            }
            else{
                //percorro tutta la lista e aggiungo all'ultimo
                elm * l;
                l=(elm *)malloc(sizeof(elm));
                l=studente[i].t;
                while(l->prox!=NULL){
                    l=l->prox;
                }
                numero=(char *)malloc(20*sizeof(char));
                d=0;
                c=getchar();
                while(c!=' '){
                    numero[d]=c;
                    ++d;
                    c=getchar();
                }
                a=atoi(numero);
                //pulisco numero
                j=0;
                while(j<d){
                    numero[j]=' ';
                    ++j;
                }
                free(numero);
                l->voto=a;
            }
            ++b;
        }
    }
    stampa(studente);
}
