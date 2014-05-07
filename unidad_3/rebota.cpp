#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
using namespace std;

#define ANCHO 80
#define ALTO 30

struct punto {
	float x;
	float y;
};

struct vector {
	struct punto posicion;
	float angulo; 
	float magnitud;
};

struct linea {
	struct punto inicio;
	struct punto fin;
};

void dibujarFondo(struct vector pelota){
	for(int i = 0; i < ANCHO; i++){
		for(int j = 0; j < ALTO; j++){
			gotoxy(i, j);
			if(i == ceil(pelota.posicion.x) && j == ceil(pelota.posicion.y)){
				cout << "o";
			} else {
				if(i == 0 || i == ANCHO - 1 || j == 0 || j == ALTO - 1){
					cout << "*";
				} else {
					cout << " ";
				}
			}
		}
	}
}

int anguloRandom(int anguloBase){

	return rand()% 11 + (anguloBase - 5);
}

struct vector calcularPelota(struct vector pelota){
	bool reboto = false;
	float siguienteX = pelota.posicion.x + sin(pelota.angulo) * pelota.magnitud;
	float siguienteY = pelota.posicion.y + cos(pelota.angulo) * pelota.magnitud;
	
	if(siguienteX >= ANCHO){
		if(pelota.angulo > 90){
			pelota.angulo -= anguloRandom(90);
		} else {
			pelota.angulo += anguloRandom(90);
		}
		reboto = true;
	}
	
	if(siguienteY >= ALTO){
		if(pelota.angulo > 270){
			pelota.angulo -= anguloRandom(270);
		} else {
			pelota.angulo -= anguloRandom(270);
		}
		reboto = true;
	}
	
	if(siguienteX <= 0){
		if(pelota.angulo > 180){
			pelota.angulo += anguloRandom(90);
		} else {
			pelota.angulo -= anguloRandom(90);
		}
		reboto = true;
	}
	
	if(siguienteY <= 0){
		if(pelota.angulo > 90){
			pelota.angulo += anguloRandom(90);
		} else {
			pelota.angulo += anguloRandom(270);
		}
		reboto = true;
	}
	
	if(reboto){
		pelota.posicion.x += sin(pelota.angulo) * pelota.magnitud;
		pelota.posicion.y += cos(pelota.angulo) * pelota.magnitud;
	} else {
		pelota.posicion.x = siguienteX;
		pelota.posicion.y = siguienteY;
	}
	
	if(pelota.posicion.x < 0){
		pelota.posicion.x = 0;
	}
	
	if(pelota.posicion.x > ANCHO){
		pelota.posicion.x = ANCHO;
	}
	
	if(pelota.posicion.y < 0){
		pelota.posicion.y = 0;
	}
	
	if(pelota.posicion.y > ALTO){
		pelota.posicion.y = ALTO;
	}
	
	return pelota;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	struct vector pelota;
	pelota.posicion.x = 0;
	pelota.posicion.y = 0;
	pelota.angulo = 315;
	pelota.magnitud = 2;
	
	char key;
	int i = 0;
	while(key != 's'){
		pelota = calcularPelota(pelota);
		
		dibujarFondo(pelota);

		usleep(100000);
		if(kbhit()){
			key = getch();
		}
	}
	
	return 0;
}
