//
//  es64.c
//  
//
//  Created by Giorgio Pizzati on 14/05/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct element{
    char n;
    struct element * next;
};
typedef struct element elm;
elm * elemento(char x){
    elm * p;
    p=(elm *) malloc(sizeof(elm));
    p->n=x;
    p->next=NULL;
    return p;
}


char chiusura(char a){
    if(a=='{'){
        return '}';
    }
    else if(a=='['){
        return ']';
    }
    else if(a=='('){
        return ')';
    }
    else{
        return '0';
    }
}
elm * cercochiusura(elm * t){
    char apertura=t->n;
    //int lunghezza=0;
    //cerco la lunghezza
    elm * l=t->next;
    /*while(l!=NULL){
        lunghezza++;
        l=l->next;
    }
    //riporto l uguale a t
    l=t;*/
    //int p=0;
 
    while(l!=NULL){
        if(l->n=='{'||l->n=='['||l->n=='('){
            l=cercochiusura(l);
        }
        else if(l->n==chiusura(apertura)){
            return l->next;
        }
        else{
            printf("errore");
            return NULL;
        }
    }
    
    /*else{
        if(t->next->n==chiusura(apertura)){
            return t->next;
        }
        else{
            printf("errore");
            return MAX_INT;
        }
    }*/
}
void controllo(elm * t){
    /*int lunghezza=0;
     //cerco la lunghezza
     elm * l=t;
     while(l!=NULL){
     lunghezza++;
     l=l->next;
     }
     
     int p=0;
     while(p<lunghezza){
     //cerco fine
     
     //trovo fine quindi pongo p=fine
     //se p=lunghezza non ci sono più elementi
     
     }*/
    
    if(cercochiusura(t)==NULL){
        printf("fatto");
    }
}
elm * addtoback(elm  * new, elm * testa){
    elm * intermedio=testa;
    while(intermedio->next!=NULL){
        intermedio=intermedio->next;
    }
    intermedio->next=new;
    return testa;
}
void printlist(elm * l){
    while(l!=NULL){
        printf("%c\n", l->n);
        l=l->next;
    }
}
int main(){
    char c;
    //creo la testa
    elm * t=NULL;
    c=getchar();
    while(c!=EOF){
        if(c=='{'||c=='['||c=='('||c=='}'||c==']'||c==')'){
            if(t==NULL){
                t=elemento(c);
            }
            else{
                t=addtoback(elemento(c),t);
            }
        }
        c=getchar();
    }
    printlist(t);
    controllo(t);
}
