//terzo.cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <TCanvas.h>
#include <TH1F.h>

double rand_range(double min, double max){
	return min + (max-min) * (1. * rand()) / (1. * RAND_MAX);
}

double rand_CLT(double xMin, double xMax, int tries){
	double x= 0.;
	for (int i =0;i<tries;i++){
		x+=rand_range(xMin,xMax);
	}
	return x/tries;
}

double f_Cauchy(double x){
	double c = 1/(M_PI*(1+x*x));
	return c;
}
double rand_TAC(double xMin, double xMax, double yMin, double yMax){
	double x=0., y=0.;
	do{
		x=rand_range(xMin,xMax);
		y=rand_range(yMin,yMax);
	} while(y>f_Cauchy(x));
	return x;
}
int main(){
	srand(time(NULL));
	double min=-5;
	double max=5;
	int nEstrazioni=10;
	int N=10000;

	TH1F pdf ("name", "title", 100, min, max);
	for (int i = 0; i< N;i++){
		double numero_casuale = rand_TAC(min, max, 0., 1/M_PI);
		std::cout << "Numero casuale: " << numero_casuale << std::endl;
		pdf.Fill(numero_casuale);
	}
	TCanvas cnv;
	pdf.Draw();
	pdf.Fit("cauchy");
	cnv.Print("istogramma.png","png");
	
	return 0;
}
