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
    for(i=0;i<2;++i){
        b=0;
        scanf("%i",&a);
        studente[i].matricola=a;
        studente[i].t=NULL;
        ++b;
        while(a!=0){
            if(b%2!=0){
                if(studente[i].t==NULL){
                    scanf("%i",&a);
                    studente[i].t=(elm*) malloc(sizeof(elm));
                    studente[i].t->insegn=a;
                }
                else{

                    elm * esame;
                    esame=(elm*)malloc(sizeof(elm));
                    scanf("%i",&a);
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
                scanf("%i",&a);
                l->voto=a;
            }
            ++b;
        }
    }
    stampa(studente);



}
