#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras);
int penalizacion(int caras, int maximo);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int a, b, c;
	cout << "Cantidad de caras del dado: ";
	cin >> a;
	cout << "\nPenalización: ";
	cin >> b;
	c = penalizacion(a, b);
	cout << endl << "\nSalio: " << c << endl;
	
	return 0;
}

int dado(int caras){
	return rand() % caras + 1;
}

int penalizacion(int caras, int maximo){
	int tirada;
	do{
		tirada = dado(caras);
	} while(tirada >= maximo);
	
	return tirada;
}
