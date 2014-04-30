#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

int lanzarDados(int tipo, int cantidad, int base){
	int resultado = 0;
	
	for(int i = 0; i < cantidad; i++){
		resultado += rand() % tipo + 1;
	}
	
	return resultado + base;
}

int calcularDano(){
	int dano = lanzarDados(6, 2, 3) - lanzarDados(4, 2, 1);
	if(dano < 0){
		dano = 0;
	}
	
	return dano;
}

int calcularCura(){
	
	return lanzarDados(6, 1, 0);
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int vidaJugador = rand() % 100 + 20;
	int vidaEnemigo = rand() % 80 + 10;
	int puntos;
	
	char respuesta = 'p';
	
	while (respuesta != 's'){
		switch(respuesta){
		case 'p':
			puntos = calcularDano();
			cout << "\nHas hecho " << puntos << " puntos de daño.\n";
			vidaEnemigo -= puntos;
			break;
		case 'c':
			puntos = calcularCura();
			cout << "\nTe has curado " << puntos << " puntos de daño.\n";
			vidaJugador += puntos;
			break;
		default:
			cout << "\nOpción invalida.\n";
		}
		
		
		if(vidaEnemigo > 10){
			puntos = calcularDano();
			cout << "Te han hecho " << puntos << " puntos de daño.\n";
			vidaJugador -= puntos;
		} else {
			puntos = calcularCura();
			cout << "El enemigo se ha curado " << puntos << " puntos de daño.\n";
			vidaEnemigo += puntos;
		}
		
		if(vidaEnemigo > 0){
			if(vidaJugador > 0){
				cout << "\nTu vida: " << vidaJugador << endl;
				cout << "La vida de tu enemigo: " << vidaEnemigo << endl;
				cout << "p => Pegar\n";
				cout << "c => Curar\n";
				cout << "s => Salir\n";
				cin >> respuesta;
			} else {
				cout << "Tu cuerpo inerte yace en el suelo.\n";
				respuesta = 's';
			}
		} else {
			cout << "Has logrado vencer a el vil asesino.\n";
			respuesta = 's';
		}
	}
	
	return 0;
}

