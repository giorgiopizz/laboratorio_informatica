#include <stdio.h>
int gdc(int a, int b){
	if(b==0){
		return a;
	}
	else{
		return gdc(b,a%b);
	}
}
int main(){
	int n=0;
	int x[2];
	for (n=0;n<3;++n){
		printf("Inserire a: ");
		scanf("%i", &x[0]);
		printf("Inserire b: ");
		scanf("%i", &x[1]);
		printf("Il risultato è: %i", gdc(x[0],x[1]));	
	}
}