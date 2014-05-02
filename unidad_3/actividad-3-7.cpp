#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int numero = rand() % 20 + 1;
	int numeroJugador = 0;
	int i = 0;
	
	while(numeroJugador != numero && i < 5){
		cout << "Ingrese un numero\n";
		cin >> numeroJugador;
		
		if(numeroJugador == numero){
			cout << "Has adivinado, el numero era " << numero << endl;
		} else {
			if(numero < numeroJugador) {
				cout << "El numero que elegiste es mayor al numero objetivo.\n";
			} else {
				cout << "El numero que elegiste es menor al numero objetivo.\n";
			}
		}
		
		i++;
	}
	
	if(i == 5){
		cout << "Se te acabaron los intentos.";
	}
	
	return 0;
}

