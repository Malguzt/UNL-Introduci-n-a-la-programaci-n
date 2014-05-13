#include <iostream>

using namespace std;

int doble(int numero);

int main(int argc, char *argv[]) {
	int a;
	
	cout << doble(8) << endl;
	
	a = doble(5);
	cout << a << endl;
	
	return 0;
}

int doble(int numero){
	
	return 2 * numero;
}
