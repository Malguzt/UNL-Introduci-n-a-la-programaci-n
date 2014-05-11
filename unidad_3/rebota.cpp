#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
using namespace std;

#define ANCHO 80
#define ALTO 30

float pelotaX = 0;
float pelotaY = 0;
float pelotaAngulo = 315;
float pelotaVelocidad = 2;

void dibujarFondo(){
	for(int i = 0; i < ANCHO; i++){
		for(int j = 0; j < ALTO; j++){
			gotoxy(i, j);
			if(i == ceil(pelotaX) && j == ceil(pelotaY)){
				cout << "o";
			} else {
				if(i == 1 || i == ANCHO - 1 || j == 1 || j == ALTO - 1){
					cout << "*";
				} else {
					cout << " ";
				}
			}
		}
	}
	
	gotoxy(0, ALTO + 2);
	cout << "Angulo: " << pelotaAngulo << "      ";
	cout << "(x, y): (" << ceil(pelotaX) << "; " << ceil(pelotaY) << ")      \n";
}

int anguloRandom(int anguloBase){
	int nuevoAngulo = rand()% 5 + (anguloBase - 2);
	
	gotoxy(0, ALTO + 4);
	cout << "Nuevo angulo: " << nuevoAngulo << "        ";

	return anguloBase;
}

void calcularPelota(){
	pelotaX += sin(pelotaAngulo) * pelotaVelocidad;
	pelotaY += cos(pelotaAngulo) * pelotaVelocidad;
	
	if(pelotaX >= ANCHO - 1){
		if(pelotaAngulo > 270){
			pelotaAngulo -= anguloRandom(90);
		} else {
			pelotaAngulo += anguloRandom(90);
		}
	}
	
	if(pelotaY >= ALTO - 1){
		if(pelotaAngulo > 270){
			pelotaAngulo -= anguloRandom(270);
		} else {
			pelotaAngulo -= anguloRandom(90);
		}
	}
	
	if(pelotaX <= 1){
		if(pelotaAngulo > 180){
			pelotaAngulo += anguloRandom(90);
		} else {
			pelotaAngulo -= anguloRandom(90);
		}
	}
	
	if(pelotaY <= 1){
		if(pelotaAngulo > 90){
			pelotaAngulo += anguloRandom(90);
		} else {
			pelotaAngulo += anguloRandom(270);
		}
	}
	
	if(pelotaX < 1){
		pelotaX = 1;
	}
	
	if(pelotaX > ANCHO - 1){
		pelotaX = ANCHO - 1;
	}
	
	if(pelotaY < 1){
		pelotaY = 1;
	}
	
	if(pelotaY > ALTO - 1){
		pelotaY = ALTO - 1;
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	char key;
	int i = 0;
	while(key != 's'){
		calcularPelota();
		
		dibujarFondo();

		usleep(100000);
		if(kbhit()){
			key = getch();
		}
	}
	
	return 0;
}
