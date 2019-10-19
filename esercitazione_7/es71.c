#include <stdio.h>
#include <stdlib.h>

int xn(){
	int x0=1;
	int b=1;
	int m=3;
	int n=0;
	int x=x0;
	while(n<m){
		x=(b*x+1)%m;
		printf("Trovato un valore tra 0 e m: %i\n", x);
		/*if(x>0&&x<m){
			printf("Trovato un valore tra 0 e m: %i\n", x);
		}*/
		n++;
	}
	return x;
}

int main(){
	printf("%i", xn());	
}
