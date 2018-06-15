#include "pizlib.h"
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
		t=addinfront(t,n);
		++i;
	}
	printlist(t);
        printf("Elimino il primo elemento\n");
	t=delfirst(t);
	printlist(t);
        printf("Elimino l'ultimo elemento\n");
        t=dellast(t);
        printlist(t);
}
