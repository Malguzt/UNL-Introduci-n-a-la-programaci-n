#include <iostream>
using namespace std;

bool se_puede(int caras, int modificador);

int main(int argc, char *argv[]) {
	int a, b, c;
	
	cout << "Cantidad de caras del dado: ";
	cin >> a;
	cout << endl << "Penalizacion o Ventaja: ";
	cin >> b;
	
	if(se_puede(a, b)){
		cout << "Se puede devolver una tirada" << endl;
	} else {
		cout << "No se puede devolver una tirada" << endl;
	}
	
	return 0;
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
