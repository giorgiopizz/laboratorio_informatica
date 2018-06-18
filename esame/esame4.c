/*826389 Giorgio Pizzati
Esame di Laboratorio di informatica del 15/06/2018
In questo programma si usa una lista concatenata 
di punti per memorizzare i punti materiali letti
tramite scanf dallo standard input*/
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
        //una funzione utile per controllare com'è fatta la lista
        //non viene usata dal programma ma è utile per il debug
        elm * l;
        l=lista->t;
        while(l!=NULL){
                printapunto(l->punto);
                l=l->prox;
        }
}
elm * elemento(pt point){
        //questa funzione crea un nuovo elemento
        //alloca dinamicamente la memoria
        //fornendo il pointer all'elemento
        elm * p;
        p=(elm *) malloc(sizeof(elm));
        if(p==NULL){
                printf("Non è presente abbastanza memoria");
                exit(EXIT_FAILURE);
        }
        p->punto=point;
        p->prox=NULL;
        return p;
}
lista * addback(lista * lista, pt punto){
        //la funzione aggiunge in coda alla lista
        elm * new;
        new=elemento(punto);
        if(lista->t!=NULL){
                //se la lista non è vuota aggiunge in coda
                lista->c->prox=new;
                lista->c=new;
        }
        else{
                //se la lista è vuota, testa e coda coincidono
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
        return lista;
}
pt cdm(lista * lista){
        pt cm;
        //xm e ym sono rispettivamente la sommatoria di x*m e y*m
        //iniziano da 0 e man mano gli si sommano la massa i-esima
        //per la coordinata(x o y) i-esima
        float xm=0;
        float ym=0;
        float m=0;
        elm * l=lista->t;
        while(l!=NULL){
                m=m+l->punto.m;
                xm=xm+l->punto.x*l->punto.m;
                ym=ym+l->punto.y*l->punto.m;
                l=l->prox;
        }
        cm.m=m;
        //la x e la y del centro di massa sono definite come
        //la sommatoria di x*m/M quindi bisogna dividere per la massa
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
                printf("Bisogna immettere s da riga di comando.\n");
                exit(EXIT_FAILURE);
        }
        else{
                s = atof(argv[1]);
        }
        //definisco la testa di una lista concatenata di punti    
        lista * list;
        list=(lista*)malloc(sizeof(lista));
        if(list==NULL){
                printf("Non è presente abbastanza memoria");
                exit(EXIT_FAILURE);
        }
        //imposto inizialmente i due pointer testa e coda a NULL perché
        //non c'è ancora alcun elemento
        list->t=NULL;
        list->c=NULL;
        printf("Benvenuto!\n");
        printf("Inserisci i punti materiali\n");
        printf("L'input deve essere del tipo x y m ed invio per ogni punto\n");
        //leggo i valori inserendoli nella lista
        list=leggivalori(list);
        //definisco il centro di massa(che è un punto) e lo calcolo
        pt cm;
        cm=cdm(list);
        printf("Il centro di massa trovato è:\n");
        printapunto(cm);
        printf("Il numero di punti che distano meno di s");
        printf(" dal centro di massa è:%i\n",minore(cm,list,s));
        //la funzione libera percorre la lista liberando la memoria allocata
        //per ogni singolo punto
        list=libera(list);
        //anche se la lista è stata liberata è necessario liberare la memoria
        //allocata per i due pointer t e c
        free(list);
        return 0;
}
/*
Piccola precisazione: è stata usata la funzione addback
invece di aggiungere in testa affinché il risultato
fosse lo stesso dell'esempio riportato su elearning.
Percorrendo la lista in un senso o nell'altro i risultato non è uguale
(differiscono per la centomillesima parte)
infatti le approssimazioni che la macchina fa sono diverse a seconda
dei numeri che sta trattando. è stata creata la struct lista per
la funzione addback per diminuire il costo computazionale
avendo già il pointer alla coda della lista
non è costretta a ripercorrerla ogni volta
*/
