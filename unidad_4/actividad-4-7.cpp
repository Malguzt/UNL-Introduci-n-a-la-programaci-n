#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras);
int ventaja(int caras, int minimo);
bool se_puede(int caras, int modificador);

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

bool se_puede(int caras, int modificador){
	bool posible = true;
	
	if(modificador < 2){
		posible = false;
	}
	
	if(modificador >= caras){
		posible = false;
	}
	
	return posible;
}

int ventaja(int caras, int minimo){
	int tirada = 0;
	if(se_puede(caras, minimo)){
		do{
			tirada = dado(caras);
		} while(tirada <= minimo);
	}
	
	return tirada;
}
