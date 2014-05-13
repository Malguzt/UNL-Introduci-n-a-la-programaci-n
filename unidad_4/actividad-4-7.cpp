#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras);
int ventaja(int caras, int minimo);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	int a, b, c;
	cout << "Cantidad de caras del dado: ";
	cin >> a;
	cout << "\nVentaja: ";
	cin >> b;
	c = ventaja(a, b);
	cout << endl << "\nSalio: " << c << endl;
	
	return 0;
}

int dado(int caras){
	return rand() % caras + 1;
}

int ventaja(int caras, int minimo){
	int tirada;
	do{
		tirada = dado(caras);
	} while(tirada <= minimo);
	
	return tirada;
}
