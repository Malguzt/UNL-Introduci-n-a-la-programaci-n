#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
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

void dibujarFondo(){
	gotoxy(0, 0);
	for(int i = 0; i < 15; i++){
		cout << "                                                                        \n";
	}
}

int calcularCura(){
	
	return lanzarDados(6, 1, 0);
}

int imprimirVida(int valor){
	if(valor < 20){
		textcolor(RED);
	} else {
		if(valor < 50){
			textcolor(YELLOW);
		} else {
			textcolor(GREEN);
		}
	}
	
	cout << valor << endl;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int vidaJugador = rand() % 100 + 20;
	int vidaEnemigo = rand() % 80 + 10;
	int puntos;
	
	char respuesta = 'p';
	
	while (respuesta != 's'){
		dibujarFondo();
		switch(respuesta){
		case 'p':
			puntos = calcularDano();
			textcolor(RED);
			gotoxy(0,10);
			cout << "\nHas hecho " << puntos << " puntos de daño.      \n";
			vidaEnemigo -= puntos;
			break;
		case 'c':
			puntos = calcularCura();
			textcolor(GREEN);
			gotoxy(0,10);
			cout << "\nTe has curado " << puntos << " puntos de daño.    \n";
			vidaJugador += puntos;
			break;
		default:
			cout << "\nOpción invalida.\n";
		}
		
		
		if(vidaEnemigo > 10){
			puntos = calcularDano();
			textcolor(RED);
			gotoxy(0,13);
			cout << "Te han hecho " << puntos << " puntos de daño.      \n";
			vidaJugador -= puntos;
		} else {
			puntos = calcularCura();
			textcolor(GREEN);
			gotoxy(0,13);
			cout << "El enemigo se ha curado " << puntos << " puntos de daño.       \n";
			vidaEnemigo += puntos;
		}
		
		if(vidaEnemigo > 0){
			if(vidaJugador > 0){
				textcolor(BLUE);
				gotoxy(0,0);
				cout << "\nTu vida: ";
				imprimirVida(vidaJugador);
				
				textcolor(BLUE);
				cout << "La vida de tu enemigo: ";
				imprimirVida(vidaEnemigo);
				
				textcolor(BLUE);
				cout << "p => Pegar\n";
				cout << "c => Curar\n";
				cout << "s => Salir\n";
				respuesta = getch();
			} else {
				textbackground(RED);
				textcolor(BLACK);
				cout << "Tu cuerpo inerte yace en el suelo.      \n";
				respuesta = 's';
			}
		} else {
			textbackground(GREEN);
			textcolor(BLACK);
			cout << "Has logrado vencer al vil asesino.        \n";
			respuesta = 's';
		}
	}
	
	return 0;
}

