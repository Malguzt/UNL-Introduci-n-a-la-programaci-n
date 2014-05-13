#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras, int &salida);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int a;
	if(dado(20, a)){
		cout << "Salio " << a << endl;
	} else {
		cout << "El número de lados es incorrecto.";
	}
	
	return 0;
}

int dado(int caras, int &salida){
	if(caras > 0) {
		salida = rand() % caras + 1;
		return true;
	}
	
	return false;
}
