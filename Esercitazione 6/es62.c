#include <stdio.h>
#include <stdlib.h>
struct element{
	int n;
	struct element * next;
};
typedef struct element elm;
elm * elemento(int x){
	elm * p;
	p=(elm *) malloc(sizeof(elm));
	p->n=x;
	p->next=NULL;
	return p;
}
elm * addinfront(elm  * new, elm * testa){
	new->next=testa;
	return new;
}
void printlist(elm * l){
	while(l!=NULL){
		printf("%i\n", l->n);
		l=l->next;
	}
}
void sumlist(elm * l){
	int s=0;
	while(l!=NULL){
		s=s+l->n;
		l=l->next;
	}
	printf("La somma è %i\n", s);
}
void minlist(elm * l){
	int min;
	min=l->n;
	while(l!=NULL){
		if(min>l->n){
			min=l->n;
		}
		l=l->next;
	}
	printf("Il minimo è %i\n", min);
}
elm * delfirst(elm * l){
	elm * t=l;
	elm * precedente=NULL;
	while(t!=NULL){
		if(t->n<0){
			printf("valore da eliminare: %i\n", t->n);
			if(precedente!=NULL){
				precedente->next=t->next;
			}
			else{
				l=t->next;	
			}			
			free(t);
			break;
		}
		precedente=t;
		t=t->next;
	}
	return l;
}

int main(){
	int n,lenght,i=1;
	//creo la testa
	elm * t;
	printf("Inserisci la lunghezza della lista: ");
	scanf("%i", &lenght);
	printf("Inserisci il primo valore della lista: ");
	scanf("%i", &n);
	t=elemento(n);
	while(i<lenght){
		printf("Inserisci il valore %i della lista: ", i);
		scanf("%i", &n);
		t=addinfront(elemento(n), t);
		++i;
	}
	printlist(t);
	sumlist(t);
	minlist(t);
	t=delfirst(t);
	printlist(t);
}
