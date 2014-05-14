#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras = 6);
int dado(int caras, int &salida);
void imprimirMenu();
int penalizacion(int caras, int maximo);
bool se_puede(int caras, int modificador);
int ventaja(int caras, int minimo);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int resultado, opcion, caras, modificador;
	
	do{
		imprimirMenu();
		cin >> opcion;
		switch(opcion){
		case 1:
			cout << "El resultado es: " << dado() << endl;
			break;
		case 2:
			cout << "Cantidad de caras: ";
			cin >> caras;
			cout << "El resultado es: " << dado(caras) << endl;
			break;
		case 3:
			for(int i = 1; i <= 5; i++){
				cout << i << "º dado: " << dado() << endl;
			}
			break;
		case 4:
			cout << "Cantidad de caras: ";
			cin >> caras;
			cout << "Penalizador: ";
			cin >> modificador;
			resultado = penalizacion(caras, modificador);
			if(resultado){
				cout << "El resultado es: " << resultado << endl;
			} else {
				cout << "Valores invalidos.\n";
			}
			break;
		case 5:
			cout << "Cantidad de caras: ";
			cin >> caras;
			cout << "Ventaja: ";
			cin >> modificador;
			resultado = ventaja(caras, modificador);
			if(resultado){
				cout << "El resultado es: " << resultado << endl;
			} else {
				cout << "Valores invalidos.\n";
			}
			break;
		}
		
		cout << "\n=====================\n";
	} while (opcion != 0);
	
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

void imprimirMenu(){
	cout << "0 - Salir\n";
	cout << "1 - Tirar un dado de 6 caras\n";
	cout << "2 - Tirar un dado de n caras\n";
	cout << "3 - Tirada de generala\n";
	cout << "4 - Tirada con penalización\n";
	cout << "5 - Tirada con ventaja\n";
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

int penalizacion(int caras, int maximo){
	int tirada = 0;
	if(se_puede(caras, maximo)){
		do{
			tirada = dado(caras);
		} while(tirada >= maximo);
	}
	
	return tirada;
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
