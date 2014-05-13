#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras = 6);
int dado(int caras, int &salida);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int a;
	
	a = dado();
	cout << "Salio " << a << endl;
	
	a = dado(20);
	cout << "Salio " << a << endl;
	
	if(dado(20, a)){
		cout << "Salio " << a << endl;
	} else {
		cout << "El número de lados es incorrecto.";
	}
	
	return 0;
}

int dado(int caras, int &salida){
	if(caras > 0) {
		salida = dado(caras);
		return true;
	}
	
	return false;
}

int dado(int caras){
	return rand() % caras + 1;
}
