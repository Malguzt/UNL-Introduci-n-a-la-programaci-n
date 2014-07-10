#include <iostream>
using namespace std;

int main(){
	int **punteroMatriz;

	int columnas, filas;

	cout << "Ingresa el numero de filas: ";
	cin >> filas;

	cout << "\nIngresa el numero de columnas: ";
	cin >> columnas;

	punteroMatriz = new int* [filas];
	for(int i = 0; i < filas; i++){
		punteroMatriz[i] = new int[columnas];
	}

	cout << "Elementos de la matriz con sus direcciones: \n";
	for (int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			punteroMatriz[i][j] = i + j;
			cout << punteroMatriz[i][j] << "--> ";
			cout << &punteroMatriz[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Elementos de la matriz con sus direcciones, con aritmética de punteros: \n";
	for (int i = 0; i < filas; ++i){
		for(int j = 0; j < columnas; ++j){
			*(*(punteroMatriz + i) + j) = i + j;
			cout << *(*(punteroMatriz + i) + j) << "--> ";
			cout << &punteroMatriz[i][j] << " | ";
		}
		cout << endl;
	}

	for(int i = 0; i < filas; i++){
		delete[] punteroMatriz[i];
	}

	delete[] punteroMatriz;

	return 0;
}