#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio2.h>
using namespace std;

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
	gotoxy(0, 0);
	for(int i = 0; i < 60; i++){
		for(int j = 0; j < 30; j++){
			gotoxy(i, j);
			if(i == ceil(pelota.posicion.x) && j == ceil(pelota.posicion.y)){
				cout << "o";
			} else {
				cout << " ";
			}
		}
	}
}

struct vector calcularPelota(struct vector pelota){
	pelota.posicion.x += sin(pelota.angulo) * pelota.magnitud;
	pelota.posicion.y += cos(pelota.angulo) * pelota.magnitud;
	
	return pelota;
}

int main(int argc, char *argv[]) {
	struct vector pelota;
	pelota.posicion.x = 0;
	pelota.posicion.y = 0;
	pelota.angulo = 315;
	pelota.magnitud = 1;
	
	char key;
	int i = 0;
	while(key != 's'){
		clrscr();
		pelota = calcularPelota(pelota);
		
		dibujarFondo(pelota);
		
		usleep(100000);
		if(kbhit()){
			key = getch();
		}
	}
	
	return 0;
}
