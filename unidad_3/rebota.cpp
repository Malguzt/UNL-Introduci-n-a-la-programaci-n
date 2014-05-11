#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
using namespace std;

#define ANCHO 80
#define ALTO 30

float pelotaX = 2;
float pelotaY = 2;
int pelotaAngulo = 315;
float pelotaVelocidad = 0.02;

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
	cout << "Angulo: " << pelotaAngulo << " cos: " << cos(pelotaAngulo) << " sin: " << sin(pelotaAngulo);
	cout << "(x, y): (" << pelotaX << "; " << pelotaY << ")      \n";
}

void calcularPelota(){
	cout << "\nSeno: " << sin(pelotaAngulo) << " Coseno: " << cos(pelotaAngulo);
	if(pelotaAngulo > 180){
		pelotaY += sin(pelotaAngulo) * pelotaVelocidad;
	} else {
		pelotaY -= sin(pelotaAngulo) * pelotaVelocidad;
	}
	pelotaX += cos(pelotaAngulo) * pelotaVelocidad;
	
	if(pelotaX > ANCHO - 1){
		pelotaX = ANCHO - 1;
		if(pelotaAngulo > 270){
			pelotaAngulo -= 90;
		} else {
			pelotaAngulo += 90;
		}
	}
	
	if(pelotaX < 1){
		pelotaX = 1;
		if(pelotaAngulo > 180){
			pelotaAngulo += 90;
		} else {
			pelotaAngulo -= 90;
		}
	}
	
	if(ceil(pelotaY) > ALTO - 1){
		pelotaY = ALTO - 1;
		if(pelotaAngulo > 270){
			pelotaAngulo -= 270;
		} else {
			pelotaAngulo -= 90;
		}
	}
	
	if(pelotaY < 1){
		pelotaY = 1;
		if(pelotaAngulo > 90){
			pelotaAngulo += 90;
		} else {
			pelotaAngulo += 270;
		}
	}
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	
	char key;
	int i = 0;
	while(key != 's'){
		calcularPelota();
		
		dibujarFondo();

		//usleep(100000);
		if(kbhit()){
			key = getch();
		}
		
		gotoxy(0, ALTO + 8);
		cout << "Vuelta: " << i++;
	}
	
	return 0;
}
