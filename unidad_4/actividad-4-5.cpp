#include <iostream>
using namespace std;

void intercambio(int &var1, int &var2);

int main(int argc, char *argv[]) {
	int a,b;
	
	a = 5;
	b = 10;
	
	intercambio(a, b);
	
	cout << "a= " << a << " b= " << b << endl;
	
	return 0;
}

void intercambio(int &var1, int &var2){
	int aux = var1;
	var1 = var2;
	var2 = aux;
}
