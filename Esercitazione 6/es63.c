#include <stdio.h>
#include <stdlib.h>
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
void controlla(elm * l){
	
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
	controlla(t);
}
