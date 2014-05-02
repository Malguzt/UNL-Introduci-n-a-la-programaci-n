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
	int numeroAnterior = 0;
	int i = 0;
	
	while(numeroJugador != numero && i < intentos){
		cout << "Ingrese un numero\n";
		numeroAnterior = numeroJugador;
		cin >> numeroJugador;
		
		if(numeroJugador == numero){
			cout << "Has adivinado, el numero era " << numero << endl;
		} else {
			if(i > 0){
				int diferencia = abs(numero - numeroJugador);
				int diferenciaAnterior = abs(numero - numeroAnterior);
				
				if(diferencia == diferenciaAnterior) {
					cout << "Templado\n";
				} else {
					if(diferencia < diferenciaAnterior){
						cout << "Caliente\n";
					} else {
						cout << "Frio\n";
					}
				}
			}
		}
		
		i++;
	}
	
	if(i == intentos){
		cout << "Se te acabaron los intentos.";
	}
	
	return 0;
}

