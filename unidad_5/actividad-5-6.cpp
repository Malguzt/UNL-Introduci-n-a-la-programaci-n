#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int dado(int caras = 6);
void ordenar(int *numeros);
bool comprobarGenerala(int *numeros);
bool comprobarFull(int *numeros);
bool comprobarPoker(int *numeros);
bool comprobarEscalera(int *numeros);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int resultados[5];
	
	for(int i = 0; i < 5; i++){
		resultados[i] = dado();
	}
	
	ordenar(resultados);
	
	if(comprobarEscalera(resultados)){
		cout << "El resultado de las tiradas es una escalera\n";
	}
	
	if(comprobarFull(resultados)){
		cout << "El resultado de las tiradas es un full\n";
	}
	
	if(comprobarPoker(resultados)){
		cout << "El resultado de las tiradas es un poker\n";
	}
	
	if(comprobarGenerala(resultados)){
		cout << "El resultado de las tiradas es una generala\n";
	}
	
	cout << "[";
	for(int i = 0; i < 5; i++){
		cout << resultados[i];
		if(4 == i) {
			cout << "]\n";
		} else {
			cout << ", ";
		}
	}
	
	return 0;
}

int dado(int caras){
	return rand() % caras + 1;
}

void ordenar(int *numeros){
	int aux;
	bool ordenado = false;
	
	while (!ordenado){
		ordenado = true;
		
		for(int i = 0; i < 5; i++){
			if(numeros[i] > numeros[i + 1]){
				ordenado = false;
				
				aux = numeros[i];
				numeros[i] = numeros[i + 1];
				numeros[i + 1] = aux;
			}
		}
	}
}

bool comprobarEscalera(int *numeros){
	bool esEscalera = true;
	
	for(int i = 1; i <= 5; i++){
		esEscalera&= numeros[i - 1] == i;
	}
	
	if(!esEscalera){
		esEscalera = true;
		for(int i = 2; i <= 6; i++){
			esEscalera &= numeros[i - 2] == i;
		}
	}
	
	if(!esEscalera){
		esEscalera = true;
		for(int i = 3; i <= 6; i++){
			esEscalera &= numeros[i - 2] == i;
		}
		esEscalera &= numeros[0] == 1;
	}
}

bool comprobarFull(int *numeros){
	bool esFull;
	
	esFull = numeros[0] == numeros[1] && numeros[3] == numeros[4];
	esFull &= numeros[1] == numeros[2] || numeros[2] == numeros[3];
	
	return esFull;
}

bool comprobarPoker(int *numeros){
	bool esPoker;
	
	esPoker = numeros[1] == numeros[2] && numeros[2] == numeros[3];
	esPoker &= numeros[0] == numeros[1] || numeros[3] == numeros[4];
	
	return esPoker;
}

bool comprobarGenerala(int *numeros){
	bool esGenerala = true;
	
	for(int i = 0; i < 4; i++){
		esGenerala &= numeros[i] == numeros[i + 1];
	}
	
	return esGenerala;
}
