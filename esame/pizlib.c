#include "pizlib.h"
elm * elemento(int n){
        elm * p;
        p=(elm *) malloc(sizeof(elm));
        p->n=n;
        p->prox=NULL;
        return p;
}
elm * addinfront(elm * t, int n){
        elm * new;
        new=elemento(n);
        new->prox=t;
	return new;
}
elm * addback(elm * t, int n){
        elm * l;
        elm * new;
        new=elemento(n);
        l=t;
        while(l->prox!=NULL){
                l=l->prox;
        }
        l->prox=new;
        return t;
}
elm * delfirst(elm * t){
        elm * l=t;
        t=l->prox;
        free(l);
        return t;
}
elm * dellast(elm * t){
        elm * l=t;
	while(l->prox->prox!=NULL){
                l=l->prox;
        }
        free(l->prox);
        l->prox=NULL;
	return l;
}
/*elm * delatpos(elm *t, int x){
        elm * l=t;
	elm * precedente=NULL;
	while(l!=NULL){
        	if(precedente!=NULL){
        		precedente->prox=l->prox;
        	}
        	else{
        		l=l->next;
        	}
        	free(l);
        	break;
                precedente=l;
                l=l->next;
        }
	return l;
}*/
void printlist(elm * t){
        while(t!=NULL){
		printf("%i\n", t->n);
		t=t->prox;
	}
}
