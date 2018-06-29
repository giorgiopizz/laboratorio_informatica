#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void stmpvect(int vec[], int lenght){
	for(int i=0; i<lenght;i++){
		printf("Il valore alla posizione %i, vale %i\n", i, vec[i]);
	}
}
int cerca(int vect[],int elm,int lenght){
	int n=0;
    	if(lenght==0){
        	printf("Il valore cercato non esiste\n");
        	exit(EXIT_FAILURE);
    	}
	//è necessario distinguere tra una lista con elementi pari e una con elementi
	//dispari perché in un caso, l'elemento a metà esiste(dispari), nell'altro si sceglie il precedente(pari)
	else if(lenght%2==0){
		//n non è a metà perché non esiste quindi si sceglie quello appena prima della metà esatta
		n=lenght/2-1;	
		stmpvect(vect, lenght);
        	if(elm<vect[n]){
            		//copio il pezzo di vettore su uno nuovo
			//la lunghezza di questo vettore sarà metà della lunghezza originale -1
			//perché abbiamo scelto come elemento a metà quello un po' prima
			int vec[lenght/2-1];
			for(int x=0;x<n;x++){
				vec[x]=vect[x];
			}
			return cerca(vec, elm, lenght/2-1);
		}
		else if(elm>vect[n]){
			int vec[lenght/2];
			//qui il pezzo di vettore da copiare inizia alla posizione dopo la metà
			for(int x=n+1;x<lenght;x++){
				vec[x-n-1]=vect[x];
			}
			return cerca(vec,elm, lenght/2)+n+1;
		}
		else if(elm==vect[n]){
			return n+1;
		}
	}
	//in questo caso la lunghezza è dispari
	else{
		n=lenght/2;
		stmpvect(vect, lenght);
		if(elm<vect[n]){
			//copio il pezzo di vettore su uno nuovo
			int vec[lenght/2];
			for(int x=0;x<n;x++){
				vec[x]=vect[x];
			}
			return cerca(vec, elm, lenght/2);
		}
		else if(elm>vect[n]){
			//copio il pezzo di vettore su uno nuovo
			int vec[lenght/2];
			for(int x=n+1;x<lenght;x++){
				vec[x-n-1]=vect[x];
			}
			return cerca(vec,elm, lenght/2)+n+1;
		}
		else if(elm==vect[n]){
			return n+1;
		}
	}
	
}

int main(){
	int lenght;
	scanf("%i",&lenght);
	int vect[lenght];
	for (int i=0; i<lenght;i++){
		printf("Inserisci il valore: ");
		scanf("%i", &vect[i]);
	}
	int elm;
	printf("Inserisci il valore da cercare: ");
	scanf("%i", &elm);
	printf("L'elemento è stato trovato alla posizione %i\n", cerca(vect, elm, lenght));
}
