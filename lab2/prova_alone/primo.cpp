#include <iostream>

int main(){
	int * vec;
	int * num;
	vec = new int(11);
	
	num= new int(19);
	vec = num;
	std::cout << *vec;
	delete vec;
}
