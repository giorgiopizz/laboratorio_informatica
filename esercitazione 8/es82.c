#include <stdio.h>
#include <stdlib.h>
struct elm{
    int n;
    struct elm * p;
};
typedef struct elm elm;

struct nodi{
    int x;
    elm * t;
};
void grado(struct nodi nodi[],int x){
    int i;
    int gradi[]={0,0,0,0};
    elm * l;
    for(i=0;i<x;++i){
        l=nodi[i].t;
        while(l!=NULL){
            printf("%i\n", l->n);
            gradi[i]++;
            gradi[l->n]++;
            l=l->p;
        }
    }
    for(i=0;i<x;++i){
        printf("Il grado per il nodo %i è %i\n",i, gradi[i]);
    }
}
int main(){
    int z=0;
    int n;
    int i=0;
    scanf("%d", &n);
    struct nodi nodi[n];
    for(i=0;i<n;++i){
        nodi[i].x=i;
        nodi[i].t=NULL;
    }
    int w,y;
    while(z!=-1){
        scanf("\n(%d,%d)", &w,&y);
        if(w==y){
            z=-1;
            break;
        }

        //printf("(%d,%d)\n", w,y);
        //aggiungo alla testa di nodi[x] l'elemento y

        if(nodi[w].t==NULL){
            nodi[w].t=(elm*)malloc(sizeof(elm));
            nodi[w].t->n=y;
            nodi[w].t->p=NULL;
        }
        else{
            elm * l;
            elm * new;
            new=(elm*)malloc(sizeof(elm));
            new->n=y;
            new->p=NULL;
            l=nodi[w].t;
            while(l->p!=NULL){
                l=l->p;
            }
            l->p=new;
        }
    }
    //printa(nodi,n);
    grado(nodi,n);
}
