//secondo.cpp
#include <iostream>
using namespace std;

int * creaVettore(int * vettore, int dim){
	vettore = new int[dim];
	vettore[0]=20;
	//seppur creato all'interno della funzione e modificato
	//è possibile passarlo alla main con l'assegnazione
	//non è necessario il return
}
int main(){
	int * vec;
	vec = creaVettore(vec, 3);
	cout << vec[0]<<"\n";
	delete[] vec;
}
