#include <iostream>
#include "lib.h"

int main(){
	std::cout << "Primo programma in c++\n";
	int num;
	std::cin >> num;
	std::cout << incrementa(num)<<std::endl;
	return 0;
}
