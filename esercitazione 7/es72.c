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
        printf("Il valore cercato non esiste");
        return 0;
    }
	else if(lenght%2==0){
		n=lenght/2-1;	
		stmpvect(vect, lenght);
        if(elm<vect[n]){
		//if(elm<vect[n]&&lenght>0){
            //copio il pezzo di vettore su uno nuovo
			int vec[lenght/2];
			for(int x=0;x<=n;x++){
				vec[x]=vect[x];
			}
			return cerca(vec, elm, lenght/2);
		}
        else if(elm>vect[n]){
		//else if(elm>vect[n]&&lenght>0){
			int vec[lenght/2];
			for(int x=n+1;x<lenght;x++){
				vec[x-n-1]=vect[x];
			}
			return cerca(vec,elm, lenght/2)+n+1;
		}
		else if(elm==vect[n]){
			return n+1;
		}
		else{
			exit(EXIT_FAILURE);
			return -1;	
		}
	}
	else{
		n=lenght/2;
		stmpvect(vect, lenght);
		if(elm<vect[n]&&lenght>0){
			int vec[lenght/2];
			for(int x=0;x<n;x++){
				vec[x]=vect[x];
			}
			return cerca(vec, elm, lenght/2);
		}
		else if(elm>vect[n]&&lenght>0){
			int vec[lenght/2];
			for(int x=n+1;x<lenght;x++){
				vec[x-n-1]=vect[x];
			}
			return cerca(vec,elm, lenght/2)+n+1;
		}
		else if(elm==vect[n]){
			return n+1;
		}
		else{
			exit(EXIT_FAILURE);
			return -1;	
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
	printf("L'elemento è stato trovato alla posizione %i-esima", cerca(vect, elm, lenght));
}
