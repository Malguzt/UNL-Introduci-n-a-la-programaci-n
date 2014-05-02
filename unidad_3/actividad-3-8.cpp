#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	int max;
	int min;
	int intentos;
	cout << "¿Que numero quiere que sea el valor minimo a adivinar?\n";
	cin >> min;
	while (min <= 0){
		cout << "Valor invalido. Por favor ingrese un valor mayor a cero.\n";
		cin >> min;
	}
	
	cout << "¿Que numero quiere que sea el valor maximo a adivinar?\n";
	cin >> max;
	while (max <= min + 2){
		cout << "Valor invalido. Por favor ingrese un valor mayor que el minimo + 2.\n";
			cin >> max;
	}
	
	cout << "¿Cuantos intentos quiere probar?\n";
	cin >> intentos;
	int rango = (max - min + 1);
	while (intentos >= rango){
		cout << "Valor invalido. Por favor ingrese un valor menor al rango de posibilidades.\n";
		cin >> intentos;
	}
	
	srand(time(NULL));
	int numero = rand() % rango + min;
	int numeroJugador = 0;
	int i = 0;
	
	while(numeroJugador != numero && i < intentos){
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

