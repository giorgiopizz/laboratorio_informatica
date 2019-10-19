// c++ -o main myLib.cc istogramma.cc main.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "istogramma.h"
#include "myLib.h"

int main () {
	const int Nbin=30;
	const float min=0.;
	const float max=10.;
	//costruisco un oggetto di tipo istogramma
	istogramma MyHisto (Nbin, min, max);
	
	int N=10000;
	int estrazioni=10;
	float random;
	for (int i=0; i<N; i++) {
		random = rand_CLT (min, max, estrazioni);
		MyHisto.Fill(random);
	}
	
	std::cout<<"Media = "<< MyHisto.GetMean() <<std::endl;
	std::cout<<"Dev.Std = "<< MyHisto.GetRMS() <<std::endl;
	
	MyHisto.Print();		
	return 0;
}



