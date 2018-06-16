//esame3
//si usa una lista concatenata per immagazzinare i punti
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define K 50
//un punto materiale ha 3 attributi la massa, e due coordinate spaziali
struct punto{
        float x;
        float y;
        float m;
};
typedef struct punto pt;
//elemento di una lista concatenata
struct elm{
        pt punto;
        struct elm * prox;
};
typedef struct elm elm;
struct lista{
        //pointer alla testa
        elm * t;
        //pointer alla coda
        elm * c;
};
typedef struct lista lista;
void printapunto(pt a){
        printf("Il punto è:\nx:%f,\ny:%f,\nm:%f\n", a.x, a.y, a.m);
}
void printalista(lista * lista){
        elm * l;
        l=lista->t;
        while(l!=NULL){
                printapunto(l->punto);
                l=l->prox;
        }
}
elm * elemento(pt point){
        elm * p;
        p=(elm *) malloc(sizeof(elm));
        if(p==NULL){
                exit(EXIT_FAILURE);
        }
        p->punto=point;
        p->prox=NULL;
        return p;
}
lista * addback(lista * lista, pt punto){
        elm * new;
        new=elemento(punto);
        if(lista->t!=NULL){
                lista->c->prox=new;
                lista->c=new;
        }
        else{
                lista->t=new;
                lista->c=new;
        }
        return lista;
}

lista * leggivalori(lista * lista){
        pt punto;
        //leggo i valori tramite scanf
        //essendoci k punti, itero la lettura k volte
        int i;
        for(i=0;i<K;++i){
                printf("Inserisci i dati per il punto %i\n",i+1);
                scanf("%f %f %f", &punto.x, &punto.y, &punto.m);
                lista=addback(lista, punto);
        }
        //printalista(lista);
        return lista;
}
pt cdm(lista * lista){
        pt cm;
        //xm e ym sono rispettivamente la sommatoria di x*m e y*m
        //iniziano da 0 e man mano gli si sommano la massa i-esima
        //per la coordinata i-esima
        float xm=0;
        float ym=0;
        float m=0;
        elm * l=lista->t;
        if(lista->t==NULL){
                exit(EXIT_FAILURE);
        }
        while(l!=NULL){
                m=m+l->punto.m;
                xm=xm+l->punto.x*l->punto.m;
                printf("%f\n",m);
                ym=ym+l->punto.y*l->punto.m;
                l=l->prox;
        }
        cm.m=m;
        //la x e la y del centro di massa sono definite come
        // la sommatoria di x*m/M quindi bisogna dividere per la massa
        cm.x=xm/m;
        cm.y=ym/m;
        return cm;
}
float distanza(pt a, pt b){
        float dist;
        //la distanza tra due punti è definita come
        //la radice della somma dei quadrati delle sue coordinate
        dist=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
        return dist;
}
int minore(pt cm, lista * lista,float s){
        //j indice di quanti numeri sono a
        //distanza inferiore di s, infatti all'inizio è 0
        int j=0;
        elm * l=lista->t;
        //percorro la lista per studiare ogni punto
        while(l!=NULL){
                //controllo se la distanza del punto è minore di s
                if(distanza(cm, l->punto)<s){
                        //in questo caso incremento l'indice;
                        ++j;
                }
                l=l->prox;
        }
        return j;
}
lista * libera(lista * lista){
        //libero la lista dall'ultimo elemento
        //funzione ricorsiva che elimina l'ultimo elemento della lista
        //viene richiamata finchè non rimangono elementi
        if(lista->t->prox!=NULL){
                elm * l=lista->t;
                //percorro tutta la lista fino al penultimo elemento
                while(l->prox->prox!=NULL){
                        l=l->prox;
                }
                //essendo l il penultimo elemento
                //libero la memoria del successivo
                free(l->prox);
                l->prox=NULL;
                lista->c=l;
                //richiamo la funzione
                lista=libera(lista);
        }
        else{
                //in questo caso basta eliminare t
                free(lista->t);
                lista->t=NULL;
                lista->c=NULL;
        }
        return lista;
}
int main(int argc, char * argv[]){
        //dichiaro la variabile s di
        //le sarà assegnato il valore tramite riga di comando
        float s;
        if (argc != 2) {
                //il programma prende solo un argomento che è s
                exit(EXIT_FAILURE);
        }
        else{
                s = atof(argv[1]);
        }
        //definisco la testa di una lista concatenata di punti
        lista * list;
        list=(lista*)malloc(sizeof(lista));
        if(list==NULL){
                exit(EXIT_FAILURE);
        }
        list->t=NULL;
        list->c=NULL;
        printf("Benvenuto!\n");
        printf("Inserisci i punti materiali\n");
        printf("L'input deve essere del tipo x y m per un punto\n");
        //leggo i valori
        list=leggivalori(list);
        //definisco il centro di massa(che è un punto) e lo calcolo
        pt cm;
        cm=cdm(list);
        printf("Il centro di massa trovato è:\n");
        printapunto(cm);
        printf("Il numero di punti che distano meno di s");
        printf(" dal centro di massa è:%i\n",minore(cm,list,s));
        list=libera(list);
        free(list);
}
/*
Piccola precisazione: è stata usata la funzione addback
invece di addinfront affinchéil risultato sia lo stesso dell'esempio
riportato su elearning.
Percorrendo la lista in un senso o nell'altro i risultato non è uguale
infatti le approssimazioni che la macchina fa sono diverse a seconda
dei numeri che sta trattando. è stata creata la struct lista per
la funzione addback, avendo già il pointer alla coda della lista
non è costretta a ripercorrerla ogni volta

*/
